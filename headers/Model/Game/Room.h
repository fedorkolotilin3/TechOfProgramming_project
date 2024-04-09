//
// Created by fedorkolotilin on 07.04.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_ROOM_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_ROOM_H_
#include <string>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

class Room {
  std::string name;
  int users_count;
  std::string creator_name;
 public:
  Room(const std::string &name, int users_count, const std::string &creator_name);
 public:
  friend void to_json(json& j, const Room& room);
  friend void from_json(const json& j, Room& room);
  Room();
  Room(const std::string &name);
  void SetName(std::string name);
  const std::string GetName() const;
  int GetUsersCount() const;
  const std::string &GetCreatorName() const;
};
#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_ROOM_H_
