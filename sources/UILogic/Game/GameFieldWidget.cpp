#include "GameFieldWidget.h"
//#include "math.h"
#include "FieldStructure.h"
#include <iostream>
//#include "my_geometry.h"

GameFieldWidget::GameFieldWidget() : Widget() {
  OnCreate();
}
GameFieldWidget::GameFieldWidget(Widget* parent) : Widget(parent) {
  OnCreate();
}

//const double kPi = acos(-1);
//const int field_center_x = 700;
//const int field_center_y = 370;
//const int field_scale = 75;
//const double split_k = 1.05;
//const double clickable_polygon_k = 0.6;
//
//QVector<QPoint> GenerateHexagon(double x, double y, double scale) {
//  QVector<QPoint> ans;
//  for (int i = 0; i < 6; i++) {
//    double i_x = cos(2 * kPi / 6 * i) * scale + x + field_center_x;
//    double i_y = sin(2 * kPi / 6 * i) * scale + y + field_center_y;
//    ans.push_back(QPoint(i_x, i_y));
//  }
//  return ans;
//}
//QPolygon PolygonResize(QPolygon& poly, double koef) {
//  QPoint center = (poly[0] + poly[3]) / 2;
//  QPolygon answer;
//  for (auto point : poly) {
//    point = center + (point - center) * koef;
//    answer.push_back(point);
//  }
//  return answer;
//}
//QPolygon PolygonResize(std::vector<Point> poly, double koef) {
//  QPolygon answer;
//  for (auto point : poly) {
//    point *= koef;
//    answer.push_back(QPoint(point.x, point.y));
//  }
//  return answer;
//}
//
//QVector<QPoint> GenerateHexagon(QPair<double, double> pair, double scale) {
//  return GenerateHexagon(pair.first, pair.second, scale);
//}
//
//QPair<double, double> ConvertCoords(std::pair<int, int> pair, double scale) {
//  Point vec_x(1.5 * split_k, sqrt(3) / 2 * split_k);
//  Point vec_y(1.5 * split_k, - sqrt(3) / 2 * split_k);
//  Point coords = vec_x * pair.first + vec_y * pair.second;
//  coords *= field_scale;
//  return {coords.x, coords.y};
//
//}

void GameFieldWidget::OnCreate() {
//  FieldStructure f("Data/test_field.xml");
//  auto vec = f.GetContent();
//  this->struct_vector = vec;
  this->setStyleSheet("border: 3px solid red");
//  setFrameStyle(QFrame::Panel | QFrame::Raised);
//  for (int i = 0; i < vec.size(); i++) {
//    auto loc_polygon = QPolygon(GenerateHexagon(ConvertCoords(vec[i].second, field_scale), field_scale));
//    this->polygons.push_back(loc_polygon);
//    this->click_polygons.push_back(PolygonResize(loc_polygon, clickable_polygon_k));
//  }
}

void GameFieldWidget::mousePressEvent(QMouseEvent* event) {
  field.Click(event->x(), event->y());
  this->repaint();
//  for (int i = 0; i < polygons.size(); i++) {
//    if (click_polygons[i].containsPoint(event->pos(), Qt::FillRule::WindingFill)) {
//      std::cerr << "click" << " " << struct_vector[i].first.GetTypeString() << '\n';
//    }
//  }
}

void GameFieldWidget::paintEvent(QPaintEvent* event) {
  QPainter painter_1(this);
  field.Draw(painter_1);
//  QBrush fill_brush;
//  fill_brush.setStyle(Qt::SolidPattern);
//  QWidget::paintEvent(event);
//  for (int i = 0; i < polygons.size(); i++) {
//    auto& poly = polygons[i];
//    QPainterPath local_path;
//    local_path.addPolygon(poly);
//    fill_brush.setColor(struct_vector[i].first.GetColor());
////    painter_1.drawPolygon(poly);
//    painter_1.fillPath(local_path, fill_brush);
//  }
}