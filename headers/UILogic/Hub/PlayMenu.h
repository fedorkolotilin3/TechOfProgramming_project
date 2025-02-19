//
// Created by fedorkolotilin on 14.03.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_UILOGIC_HUB_PLAYMENU_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_UILOGIC_HUB_PLAYMENU_H_

#include "Widget.h"
#include "Button.h"


class PlayMenu : public Widget {
 private:
  Button start_tutorial;
  Button start_local_game;
  Button start_global_game;
  Button exit;
 public:
  PlayMenu();
  PlayMenu(Widget* widget);
  void OnCreate();
};

#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_UILOGIC_HUB_PLAYMENU_H_
