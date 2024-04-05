#include "Hex.h"
#include "HexView.h"

//
// Created by fedorkolotilin on 05.04.24.
//
const double kPi = acos(-1);

std::vector<Point> HexView::GenerateMyHexagon(double x, double y, double scale, double field_center_x, double field_center_y) {
  std::vector<Point> ans;
  for (int i = 0; i < 6; i++) {
    double i_x = cos(2 * kPi / 6 * i) * scale + x + field_center_x;
    double i_y = sin(2 * kPi / 6 * i) * scale + y + field_center_y;
    ans.push_back(Point(i_x, i_y));
  }
  return ans;
}

QVector<QPoint> HexView::GenerateHexagon(double x, double y, double scale, double field_center_x, double field_center_y) {
  QVector<QPoint> ans;
  for (int i = 0; i < 6; i++) {
    double i_x = cos(2 * kPi / 6 * i) * scale + x + field_center_x;
    double i_y = sin(2 * kPi / 6 * i) * scale + y + field_center_y;
    ans.push_back(QPoint(i_x, i_y));
  }
  return ans;
}
QPolygon HexView::PolygonResize(QPolygon& poly, double koef) {
  QPoint center = (poly[0] + poly[3]) / 2;
  QPolygon answer;
  for (auto point : poly) {
    point = center + (point - center) * koef;
    answer.push_back(point);
  }
  return answer;
}
QPolygon HexView::PolygonResize(std::vector<Point> poly, double koef) {
  QPolygon answer;
  for (auto point : poly) {
    point *= koef;
    answer.push_back(QPoint(point.x, point.y));
  }
  return answer;
}

QVector<QPoint> HexView::GenerateHexagon(QPair<double, double> pair, double scale, double field_center_x, double field_center_y) {
  return GenerateHexagon(pair.first, pair.second, scale, field_center_x, field_center_y);
}

QPair<double, double> HexView::ConvertCoords(std::pair<int, int> pair, double scale, double split_k, double field_scale) {
  Point vec_x(1.5 * split_k, sqrt(3) / 2 * split_k);
  Point vec_y(1.5 * split_k, - sqrt(3) / 2 * split_k);
  Point coords = vec_x * pair.first + vec_y * pair.second;
  coords *= field_scale;
  return {coords.x, coords.y};

}

void HexView::OnClick() {
  std::cerr << "you clicked on " << hex.GetTypeString() << " with loc_coords: " << local_center << " and global center: " <<  global_center;
}

void HexView::SetOnClik(auto function) {
  QObject::connect(this, &HexView::OnClick, function);
}

Polygon& HexView::GetMPolygonClickable() {
  return my_polygon_clickable;
}

HexView::HexView(const Hex &hex, int x, int y,
                 int g_x, int g_y, double scale, double click_scale, double split_k) :

                 hex(hex), local_center(x, y), scale(scale), click_scale(click_scale)
                 {
  global_center = MyConvertCoords({x, y}, scale, click_scale, scale);
  Polygon poly = GenerateMyHexagon(x, y, scale, g_x, g_y);
//  poly.sc
//  my_polygon_texture
}

Point HexView::MyConvertCoords(std::pair<int, int> pair, double scale, double split_k, double field_scale) {
  Point vec_x(1.5 * split_k, sqrt(3) / 2 * split_k);
  Point vec_y(1.5 * split_k, - sqrt(3) / 2 * split_k);
  Point coords = vec_x * pair.first + vec_y * pair.second;
  coords *= field_scale;
  return {coords.x, coords.y};
}
