//
// Created by fedorkolotilin on 13.03.24.
//
#include "RoomChooseMenu.h"
#include "RoomFile.h"
#include "MainMenu.h"
#include "PlayMenu.h"
#include "RoomWidget.h"

RoomChooseMenu::RoomChooseMenu() : Widget() {
  OnCreate();
}

RoomChooseMenu::RoomChooseMenu(Widget* widget) : Widget(widget) {
  SetParent(widget);
  OnCreate();
}

void RoomChooseMenu::OnCreate() {
  auto layout = new QVBoxLayout;
  widget_list = new QListWidget;
  for (int i = 0; i < 300; i++) {
    Room room_i = RoomFile("example.json").GetContent();
    room_i.SetName(room_i.GetName() + std::to_string(i));
    auto item = new RoomItem(room_i);
    auto widget_item = new QListWidgetItem;
//    widget_item->setSizeHint(QSize(item->width(), item->height()));
    widget_item->setSizeHint(QSize(0, 150));
    widget_list->addItem(widget_item);
    widget_list->setItemWidget(widget_item, item);
  }
  end_widget = new Widget;
  auto end_widget_layout = new QHBoxLayout(end_widget);
  auto exit_button = new Button;
  auto enter_button = new Button;
  exit_button->SetText("Exit");
  exit_button->SetAction([this]() -> void {
    this->ChangeWidget(new PlayMenu());
  });
  enter_button->SetText("Enter");
  enter_button->SetAction([this]() -> void {
    this->ChangeWidget(new RoomWidget());
  });
  end_widget_layout->addWidget(exit_button->GetSelfButton());
  end_widget_layout->addWidget(enter_button->GetSelfButton());
  layout->addWidget(widget_list);
  layout->addWidget(end_widget);
  setLayout(layout);
}






