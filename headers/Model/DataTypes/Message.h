//
// Created by fedorkolotilin on 19.04.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_DATATYPES_MESSAGE_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_DATATYPES_MESSAGE_H_

#include "User.h"
class Message {
 public:
  User sender;
  std::string content;
  Message(const std::string &content, const User &sender);
};

#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_DATATYPES_MESSAGE_H_
