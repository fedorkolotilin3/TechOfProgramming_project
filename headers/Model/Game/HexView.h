//
// Created by fedorkolotilin on 05.04.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_HEXVIEW_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_HEXVIEW_H_

#include <QPolygon>
#include "my_geometry.h"
#include "Hex.h"

class HexView {
  Polygon my_polygon;
  QPolygon  qPolygon;
  Hex hex;

 public:
  explicit HexView(const Hex &hex);
  static QVector<QPoint> GenerateHexagon(double x, double y, double scale, double field_center_x, double field_center_y);
  static QPolygon PolygonResize(QPolygon& poly, double koef);
  static QPolygon PolygonResize(std::vector<Point> poly, double koef);
  static QVector<QPoint> GenerateHexagon(QPair<double, double> pair, double scale, double field_center_x, double field_center_y);
  static QPair<double, double> ConvertCoords(std::pair<int, int> pair, double scale, double split_k, double field_scale);
};

#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_HEXVIEW_H_
