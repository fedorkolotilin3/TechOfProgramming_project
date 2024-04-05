//
// Created by fedorkolotilin on 05.04.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_FIELDOBJECTVIEW_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_FIELDOBJECTVIEW_H_

#include "my_geometry.h"

//TODO подумать над тем, нужен ли этот класс и как его описать

template <class Figure>
class FieldObjectView {
  Figure visual_shape;
  Figure clickable_shape;
  Point local_center;
  Point global_center;

  FieldObjectView(const FieldObjectView& other) = delete;
  FieldObjectView& operator=(const FieldObjectView& other) = delete;
  ~FieldObjectView();
};

#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_GAME_FIELDOBJECTVIEW_H_
