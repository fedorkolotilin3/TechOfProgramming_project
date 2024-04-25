//
// Created by fedorkolotilin on 19.04.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_UILOGIC_GAME_CHATWIDGET_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_UILOGIC_GAME_CHATWIDGET_H_

#include "Widget.h"
#include "Message.h"
#include "TextWidget.h"
class ChatWidget : public Widget {
  class MessageWidget : public TextWidget {
    Message message;
   public:
    MessageWidget(Widget* parent, const Message &message);
    explicit MessageWidget(const Message &message);
    void OnCreate();
  };
  std::vector<Message> messages;
 public:
  explicit ChatWidget(Widget* parent);
  ChatWidget(Widget* parent, const std::vector<Message> &messages);
  explicit ChatWidget(const std::vector<Message> &messages);
  void SetMessages(const std::vector<Message> &messages);
  const std::vector<Message> &GetMessages() const;
  ChatWidget();
  void OnCreate();
};

#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_UILOGIC_GAME_CHATWIDGET_H_
