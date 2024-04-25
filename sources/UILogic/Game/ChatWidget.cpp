#include <QListWidgetItem>
#include "ChatWidget.h"
#include "EditTextWidget.h"
#include "Button.h"

ChatWidget::ChatWidget() {
  OnCreate();
}

ChatWidget::ChatWidget(Widget* parent) : Widget(parent) {
  OnCreate();
}


void ChatWidget::OnCreate() {
  auto layout = new QGridLayout(this);
  auto messages_list = new QListWidget();
//  messages_list->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Maximum);
  for (auto& message : messages) {
    auto item = new MessageWidget(message);
    auto widget_item = new QListWidgetItem;
//    widget_item->setSizeHint(QSize(item->width(), item->height()));
    widget_item->setSizeHint(QSize(0, 30));
    messages_list->addItem(widget_item);
    messages_list->setItemWidget(widget_item, item);
  }
  auto edit_text = new EditTextWidget("type here to chat");
//  edit_text->setFixedSize(QSize(0, 60));
//  edit_text->sizeHint(QSize(0, 40));
  edit_text->setFixedHeight(60);
  auto send_button = new Button();
  send_button->SetGeometry(0, 0, 60, 60);
  send_button->SetIconBFN("../Data/Icons/send_message.png");
  send_button->SetIconFullSize();
  layout->addWidget(messages_list, 0, 0, 20, 11);
  layout->addWidget(edit_text, 20, 0, 1, 10);
  layout->addWidget(send_button, 20, 10, 1, 1);
//  auto print_message_layout = w

}

const std::vector<Message> &ChatWidget::GetMessages() const {
  return messages;
}

void ChatWidget::SetMessages(const std::vector<Message> &messages) {
  ChatWidget::messages = messages;
}

ChatWidget::ChatWidget(const std::vector<Message> &messages) : messages(messages) {
  OnCreate();
}

ChatWidget::ChatWidget(Widget* parent, const std::vector<Message> &messages) : Widget(parent), messages(messages) {
  OnCreate();
}

ChatWidget::MessageWidget::MessageWidget(const Message &message) : TextWidget(message.sender.GetUsername() + ": " + message.content), message(message) {
  OnCreate();
}

ChatWidget::MessageWidget::MessageWidget(Widget* parent, const Message &message) : TextWidget(message.sender.GetUsername() + ": " + message.content, parent), message(message) {
  OnCreate();
}

void ChatWidget::MessageWidget::OnCreate() {
//  this->setStyleSheet("border: 3px solid red");
//  auto text = TextWidget(message.sender.GetUsername() + ": " + message.content, this);
}
