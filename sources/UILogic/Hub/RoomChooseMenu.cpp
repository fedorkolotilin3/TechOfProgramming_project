//
// Created by fedorkolotilin on 13.03.24.
//
#include <iostream>
#include "RoomChooseMenu.h"
#include "RoomFile.h"
#include "MainMenu.h"
#include "PlayMenu.h"
#include "RoomWidget.h"
#include "GameClient.h"
#include "TestConnect.h"
#include "Room.h"

RoomChooseMenu::RoomChooseMenu() : Widget() {
  OnCreate();
}

RoomChooseMenu::RoomChooseMenu(Widget* widget) : Widget(widget) {
  SetParent(widget);
  OnCreate();
}

class RoomFindingThread : public QThread {
 public:
  RoomChooseMenu* object_ptr;
  explicit RoomFindingThread(RoomChooseMenu* object_ptr) : object_ptr(object_ptr) {}

 protected:
  void run() override {
    GameClient client;
    TestConnect test;
    connect(&client, &GameClient::AddRoomS, object_ptr, &RoomChooseMenu::AddRoom);
    connect(&client, &GameClient::AddRoomS, &test, &TestConnect::test);
    connect(&client, &GameClient::DeleteRoomS, &test, &TestConnect::test);
    connect(&client, &GameClient::DeleteRoomS, object_ptr, &RoomChooseMenu::DeleteRoom);
//    connect(client, &GameClient::AddRoom, parent(), &RoomChooseMenu::AddRoom);
    client.ListenRooms();
  }
};

void RoomChooseMenu::OnCreate() {
//  GameClient client;
//  std::thread room_finding(&GameClient::ListenRooms, client);
//  std::function<void(const GameClient&)> func = &GameClient::ListenRooms;
//  QThread* thread = QThread::create();
  RoomFindingThread* thread = new RoomFindingThread(this);
  thread->start();

  auto layout = new QVBoxLayout;
  widget_list = new QListWidget;
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

//void RoomChooseMenu::AddRoom(Room room) {
void RoomChooseMenu::AddRoom(QString rooms) {
//void RoomChooseMenu::AddRoom() {
  Room room = Room::from_json(rooms.toStdString());
//  Room room = RoomFile("example.json").GetContent();
//  room.SetName(room.GetName());
  auto item = new RoomItem(room);
  auto widget_item = new QListWidgetItem;
  //    widget_item->setSizeHint(QSize(item->width(), item->height()));
  widget_item->setSizeHint(QSize(0, 150));
  widget_list->addItem(widget_item);
  widget_list->setItemWidget(widget_item, item);
}

//void RoomChooseMenu::DeleteRoom(Room room) {
void RoomChooseMenu::DeleteRoom(QString room_s) {
//void RoomChooseMenu::DeleteRoom() {
  Room room;
  room.from_json(room_s.toStdString());

}






