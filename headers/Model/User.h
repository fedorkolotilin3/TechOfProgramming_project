//
// Created by fedorkolotilin on 13.03.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_USER_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_USER_H_
#include <string>
class User {
  std::string username;
 public:
  explicit User(const std::string &username);
  const std::string &GetUsername() const;
  void SetUsername(const std::string &username);
};
#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_USER_H_
