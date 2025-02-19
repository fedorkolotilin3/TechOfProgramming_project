//
// Created by fedorkolotilin on 06.04.24.
//
#include <QPainterPath>
#include <set>
#include "GameField.h"

std::vector<std::pair<int, int>> GetVertices(int x, int y) {
  std::vector<std::pair<int, int>> ans;
  std::vector<std::pair<int, int>> deltas = {{-2, -2}, {-2, 0}, {0, 2}, {2, 2}, {2, 0}, {0, -2}};
//  for (int i = -1; i < 2; i++) {
//    for (int j = -1; j < 2; j++) {
//      if (abs(i - j) <= 1 && (i != 0 || j != 0)) {
//        ans.push_back({x + (2 * i), y + (2 * j)});
//      }
//    }
//  }
  for (int i = 0; i < deltas.size(); i++) {
    ans.push_back({x + deltas[i].first, y + deltas[i].second});
  }
  return ans;
}

std::vector<std::pair<int, int>> GetVertices(std::pair<int, int> pair) {
  return GetVertices(pair.first, pair.second);
}

Point GameField::ConvertCoords(std::pair<int, int> pair, double split_k, double field_scale) {
  Point coords = vec_x * split_k * pair.first + vec_y * split_k * pair.second;
  coords *= field_scale;
  coords.rotateVec(rotation_angle);
  coords += Point(center_x, center_y);
  return {coords.x, coords.y};
}

GameField::GameField(){
  ConstructField();
}

GameField::GameField(int center_x, int center_y, int scale, double split_k, double clickable_polygon_k) :
                    center_x(center_x), center_y(center_y), scale(scale), split_k(split_k)
{
  ConstructField();
}

void GameField::ConstructField() {
  auto struct_file = FieldStructure("Data/test_field.xml");
//  hexes.clear();
  struct_vector = struct_file.GetContent();
  std::set<std::pair<int, int>> vertex_set;
  std::map<std::pair<int, int>, std::vector<int>> edges_set;
  for (int i = 0; i < struct_vector.size(); i++) {
    Point coords = ConvertCoords(struct_vector[i].second, split_k, scale);
    hexes.push_back(HexView(struct_vector[i].first, coords.x, coords.y, scale, clickable_hex_s));
    auto verts = GetVertices(struct_vector[i].second);
    for (int i = 0; i < verts.size(); i++) {
      vertex_set.insert(verts[i]);
      int next = (i + 1) % 6;
      std::pair<int, int> edge_center = {verts[i].first + verts[next].first, verts[i].second + verts[next].second};
      auto map_iter = edges_set.find(edge_center);
      if (map_iter == edges_set.end()) {
        std::vector<int> edge_borders =  {verts[i].first, verts[i].second, verts[next].first, verts[next].second};
        edges_set.insert(std::pair<std::pair<int, int>, std::vector<int>> (edge_center, edge_borders));
      }
    }
//    vertex_set.insert(struct_vector[i].second);
  }
  for (auto vertex : vertex_set) {
    Point coords = ConvertCoords(vertex, split_k, scale);
    vertices.push_back(VertexView(coords.x, coords.y, scale, clickable_ver_s));
  }
  for (auto edge : edges_set) {
    Point border_1 = ConvertCoords({edge.second[0], edge.second[1]}, split_k, scale);
    Point border_2 = ConvertCoords({edge.second[2], edge.second[3]}, split_k, scale);
    edges.push_back(EdgeView(border_1, border_2, scale, clickable_edge_s));
  }
}

void GameField::Draw(QPainter& painter) {
  for (auto& hex : hexes) {
    hex.Draw(painter);
  }
  for (auto& vert : vertices) {
    vert.Draw(painter);
  }
  for (auto& edge: edges) {
    edge.Draw(painter);
  }
//  QBrush fill_brush;
//  fill_brush.setStyle(Qt::SolidPattern);
//  for (int i = 0; i < qpolygons.size(); i++) {
//    auto& poly = qpolygons[i];
//    QPainterPath local_path;
//    local_path.addPolygon(poly);
//    fill_brush.setColor(Qt::darkRed);
//    painter.fillPath(local_path, fill_brush);
//  }
}

void GameField::Click(int x, int y) {
  for (auto& hex : hexes) {
    hex.Click(x, y);
  }
  for (auto& vert : vertices) {
    vert.Click(x, y);
  }
  for (auto& edge: edges) {
    edge.Click(x, y);
  }
//  for (int i = 0; i < click_polygons.size(); i++) {
//    auto& poly = click_polygons[i];
//    if (poly.containsPoint({static_cast<double>(x), static_cast<double>(y)})) {
//      std::cerr << "click on poly";
//    }
//  }
}

void GameField::ShuffleHexes() {
  FieldStructure f("Data/test_field.xml");
  auto vec = f.GetContent();
  for (int i = 0; i < vec.size(); i++) {
    vec[i].first = Hex::GetRandom();
  }
  FieldStructure f2("Data/test_field.xml");
  f2.SetContent(vec);
}


