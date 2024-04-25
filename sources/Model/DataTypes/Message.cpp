#include <string>
#include "User.h"
#include "Message.h"

//
// Created by fedorkolotilin on 19.04.24.
//
Message::Message(const std::__cxx11::basic_string<char> &content, const User &sender)
    : content(content), sender(sender) {}
