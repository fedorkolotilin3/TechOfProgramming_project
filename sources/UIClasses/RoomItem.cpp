#include "RoomItem.h"

RoomItem::RoomItem(Room room) : room(room) {
  OnCreate();
}

RoomItem::RoomItem(Room room, Widget* parent) : Widget(parent), room(room) {
  OnCreate();
}

void RoomItem::OnCreate() {
  room_name = new TextWidget("Room name: " + room.GetName());
  users_count = new TextWidget("users count: " + std::to_string(room.GetUsersCount()));
  creator_name = new TextWidget("Room Creator " + room.GetCreatorName());
  room_name->setFrameStyle(QFrame::Panel | QFrame::Raised);
  users_count->setFrameStyle(QFrame::Panel | QFrame::Raised);
  creator_name->setFrameStyle(QFrame::Panel | QFrame::Raised);
  auto layout = new QVBoxLayout(this);
//  layout->addWidget(room_name,-1,  Qt::AlignLeft);
//  layout->addWidget(users_count, -1, Qt::AlignCenter);
//  layout->addWidget(creator_name, -1, Qt::AlignRight);
//  room_name->setMaximumSize(QSize(0, 100));
//  users_count->setMaximumSize(QSize(0, 100));
//  creator_name->setMaximumSize(QSize(0, 100));
  layout->addWidget(room_name);
  layout->addWidget(users_count);
  layout->addWidget(creator_name);
  layout->addSpacing(this->height() / 50);
  layout->insertSpacing(0, this->height() / 50);
//  this->setStyle(QStyle());
//  this->setStyleSheet("background: yellow");
//  layout->setGeometry(QRect(0, 0, this->width(), 400));
}

void RoomItem::paintEvent(QPaintEvent* event) {
//  QPainter painter;
//  QB
  QWidget::paintEvent(event);
}

