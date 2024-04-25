#include "User.h"

User::User(const std::string &username) : username(username) {}

const std::string &User::GetUsername() const {
  return username;
}

void User::SetUsername(const std::string &username) {
  User::username = username;
}
