//
// Created by fedorkolotilin on 05.04.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_HEXVIEW_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_HEXVIEW_H_

#include <QPolygon>
#include <QPainter>
#include <QPainterPath>
#include "my_geometry.h"
#include "Hex.h"

class HexView {
  inline static int rotation_angle = -30;
  Polygon my_polygon;
  QPolygon q_polygon;
  Polygon my_clickable_polygon;
  QPolygon q_clickable_polygon;
  Hex hex;
  int x;
  int y;
  double hex_size;
  QImage texture;

  bool draw_mode = false;

  int scale = 75;
  double clickable_polygon_k = 0.6;

 public:

  HexView(const Hex &hex,
          double x,
          double y,
          int scale,
          double clickable_polygon_k,
          double hex_size = 2);
  HexView(const Hex &hex,
          std::pair<double, double> center,
          int scale,
          double clickable_polygon_k,
          double hex_size = 2);
  void Draw(QPainter& painter);
  void Click(int x, int y);

  static Polygon GenerateHexagon(double x, double y, double hex_size, double scale);
  static QPolygon PTOQP(Polygon& polygon);
  static Polygon QPTOP(QPolygon& polygon);
};

#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_HEXVIEW_H_
