//
// Created by fedorkolotilin on 05.04.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_HEXVIEW_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_HEXVIEW_H_

#include <QPolygon>
#include <QObject>
#include "my_geometry.h"
#include "Hex.h"

class HexView : QObject {
  Q_OBJECT;
  Polygon my_polygon_texture;
  Polygon my_polygon_clickable;
  QPolygon  qPolygon_texture;
  QPolygon  qPolygon_clickable;
  Hex hex;
  double scale;
  double click_scale;
  Point local_center;
  Point global_center;

 public slots:
  void OnClick();
 public:
  HexView(const Hex &hex, int x, int y, int g_x = 0, int g_y = 0, double scale = 1, double split_k = 1.05, double click_scale = 0.6);
  void SetOnClik(auto function);
  Polygon& GetMPolygonClickable();
  static QVector<QPoint> GenerateHexagon(double x, double y, double scale, double field_center_x, double field_center_y);
  static QPolygon PolygonResize(QPolygon& poly, double koef);
  static QPolygon PolygonResize(std::vector<Point> poly, double koef);
  static QVector<QPoint> GenerateHexagon(QPair<double, double> pair, double scale, double field_center_x, double field_center_y);
  static QPair<double, double> ConvertCoords(std::pair<int, int> pair, double scale, double split_k, double field_scale);
  static Point MyConvertCoords(std::pair<int, int> pair, double scale, double split_k, double field_scale);

  std::vector<Point> GenerateMyHexagon(double x, double y, double scale, double field_center_x, double field_center_y);
  };

#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_HEXVIEW_H_
