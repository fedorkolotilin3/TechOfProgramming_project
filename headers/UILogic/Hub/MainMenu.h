#ifndef TP_PROJECT_FIODORKOLOTILIN_UILOGIC_MAINMENU_H_
#define TP_PROJECT_FIODORKOLOTILIN_UILOGIC_MAINMENU_H_

#include "Widget.h"
#include "Button.h"


class MainMenu : public Widget {
 private:
  Button play_button;
  Button settings_button;
  void OnCreate();
 public:
  MainMenu();
  MainMenu(Widget* widget);
};

#endif //TP_PROJECT_FIODORKOLOTILIN_UILOGIC_MAINMENU_H_
