#include "Hex.h"
#include "HexView.h"

//
// Created by fedorkolotilin on 05.04.24.
//
HexView::HexView(const Hex &hex) : hex(hex) {}
const double kPi = acos(-1);


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