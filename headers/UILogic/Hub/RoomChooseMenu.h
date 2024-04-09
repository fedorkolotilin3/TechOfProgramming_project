//
// Created by fedorkolotilin on 13.03.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_UILOGIC_GLOBALGAMEFINDMENU_H_
#define TP_PROJECT_FIODORKOLOTILIN_UILOGIC_GLOBALGAMEFINDMENU_H_

#include <QListWidget>
#include "Widget.h"
#include "Room.h"
#include "RoomItem.h"
#include "Button.h"

class RoomChooseMenu : public Widget {
 private:
  QListWidget* widget_list;
  Widget* end_widget;
 public:
  RoomChooseMenu();
  RoomChooseMenu(Widget* widget);
  void OnCreate();
};

#endif //TP_PROJECT_FIODORKOLOTILIN_UILOGIC_GLOBALGAMEFINDMENU_H_
