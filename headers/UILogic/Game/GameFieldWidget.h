//
// Created by fedorkolotilin on 13.03.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_UILOGIC_GAME_GAMEFIELDWIDGET_H_
#define TP_PROJECT_FIODORKOLOTILIN_UILOGIC_GAME_GAMEFIELDWIDGET_H_


#include "Widget.h"
#include "Hex.h"
class GameFieldWidget : public Widget {
  Q_OBJECT
 public: signals:
  void mouse_pressed(QMouseEvent* event);
 public:
  QVector<QPolygon> polygons;
  QVector<QPolygon> click_polygons;
  std::vector<std::pair<Hex, std::pair<int, int>>> hex_vector;
 protected:
  void paintEvent(QPaintEvent* event) override;
  void mousePressEvent(QMouseEvent* event) override;
 public:
  void OnCreate();
  GameFieldWidget();
  GameFieldWidget(Widget* parent);
};

#endif //TP_PROJECT_FIODORKOLOTILIN_UILOGIC_GAME_GAMEFIELDWIDGET_H_
