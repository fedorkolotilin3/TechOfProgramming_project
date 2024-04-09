//
// Created by fedorkolotilin on 07.04.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_UICLASSES_ROOMITEM_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_UICLASSES_ROOMITEM_H_

#include "Widget.h"
#include "Room.h"
#include "TextWidget.h"

class RoomItem : public Widget{
  TextWidget* room_name;
  TextWidget* users_count;
  TextWidget* creator_name;
//  QLabel* room_name;
//  QLabel* users_count;
//  QLabel* creator_name;
  Room room;
 public:
  RoomItem(Room room);
  RoomItem(Room room, Widget* parent);
  void OnCreate();
 protected:
  void paintEvent(QPaintEvent* event) override;
};

#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_UICLASSES_ROOMITEM_H_
