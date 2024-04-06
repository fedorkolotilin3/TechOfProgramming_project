//
// Created by fedorkolotilin on 13.03.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_UILOGIC_GAME_GAMEFIELDWIDGET_H_
#define TP_PROJECT_FIODORKOLOTILIN_UILOGIC_GAME_GAMEFIELDWIDGET_H_


#include "Widget.h"
#include "Hex.h"
#include "GameField.h"
class GameFieldWidget : public Widget {
 public:
  GameField field;
 protected:
  void paintEvent(QPaintEvent* event) override;
  void mousePressEvent(QMouseEvent* event) override;
 public:
  void OnCreate();
  GameFieldWidget();
  GameFieldWidget(Widget* parent);
};

#endif //TP_PROJECT_FIODORKOLOTILIN_UILOGIC_GAME_GAMEFIELDWIDGET_H_
