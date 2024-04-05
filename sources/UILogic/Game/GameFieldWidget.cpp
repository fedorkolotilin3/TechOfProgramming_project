#include "GameFieldWidget.h"
#include "math.h"
#include "FieldStructure.h"
#include "my_geometry.h"
#include "GameField.h"

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
  std::string path = "../Data/test_feld.xml";
  GameField field(path);
  QObject::connect(this, &GameFieldWidget::mouse_pressed, &field, &GameField::MousePressEvent);

}

void GameFieldWidget::mousePressEvent(QMouseEvent* event) {
  this->mouse_pressed(event);
}

void GameFieldWidget::paintEvent(QPaintEvent* event) {
  QPainter painter_1(this);
  QBrush fill_brush;
  fill_brush.setStyle(Qt::SolidPattern);
//  QWidget::paintEvent(event);
  for (int i = 0; i < polygons.size(); i++) {
    auto& poly = polygons[i];
    QPainterPath local_path;
    local_path.addPolygon(poly);
    fill_brush.setColor(hex_vector[i].first.GetColor());
//    painter_1.drawPolygon(poly);
    painter_1.fillPath(local_path, fill_brush);
  }
}