//
// Created by fedorkolotilin on 05.04.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_EDGEVIEW_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_EDGEVIEW_H_

#include <QPainter>
#include "my_geometry.h"
class EdgeView {
  Point vertex_1;
  Point vertex_2;
  int rotation_angle;
  inline static double image_height = 0.6;
  inline static double image_width = 1.3;
  QImage texture;
  Circle my_clickable_area;
  double x;
  double y;
  double size;

  bool draw_mode = false;


  int scale = 75;
  double clickable_scale = 1;

 public:
  EdgeView();
  EdgeView(Point vertex_1,
             Point vertex_2,
             int scale,
             double clickable_scale,
             double size = 0.5);
  void Draw(QPainter& painter);
  void Click(int x, int y);
};

#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_EDGEVIEW_H_
