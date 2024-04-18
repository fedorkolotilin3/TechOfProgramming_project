//
// Created by fedorkolotilin on 10.04.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_UILOGIC_GAME_GAMEMENUWIDGET_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_UILOGIC_GAME_GAMEMENUWIDGET_H_

#include "Widget.h"
class GameMenuWidget : public Widget {
  Widget* base_widget = new Widget;
  void OnCreate();
 protected:
  void resizeEvent(QResizeEvent* resize_event) override;
 public:
  GameMenuWidget(Widget* base_widget);
  GameMenuWidget(Widget* base_widget, Widget* widget);
};

#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_UILOGIC_GAME_GAMEMENUWIDGET_H_
