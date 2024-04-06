//
// Created by fedorkolotilin on 05.04.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_VERTEXVIEW_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_VERTEXVIEW_H_

#include <QPainter>
#include "my_geometry.h"

class VertexView {
  inline static Point vec_x = {0.5, sqrt(3) / 2};
  inline static Point vec_y = {0.5, -sqrt(3) / 2};
  inline static int rotation_angle = -30;
  Circle my_circle;
  Circle my_clickable_Circle;
  double x;
  double y;
  double size;

  int scale = 75;
  double clickable_scale = 1;

 public:

  VertexView(double x,
             double y,
             int scale,
             double clickable_scale,
             double size = 0.5);
  void Draw(QPainter& painter);
  void Click(int x, int y);

};

#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_VERTEXVIEW_H_
