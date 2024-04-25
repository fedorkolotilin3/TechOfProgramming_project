#include "RoomWidget.h"
#include "ChatWidget.h"

RoomWidget::RoomWidget() : Widget() {
  OnCreate();
}

RoomWidget::RoomWidget(Widget* parent) : Widget(parent) {
  OnCreate();
}

void RoomWidget::OnCreate() {
//  this->setStyleSheet("border: 3px solid red");
  auto hor_layout = QVBoxLayout(this);
  User test_user("test_user");
  Message test_message("test_message", test_user);
  std::vector<Message> msgs(40, test_message);
  auto chat_widget = new ChatWidget(msgs);
  chat_widget->setFixedSize(600, 900);
  hor_layout.addWidget(chat_widget, 0, Qt::AlignCenter);
}
