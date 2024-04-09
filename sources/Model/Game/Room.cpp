//
// Created by fedorkolotilin on 13.03.24.
//
#include "Room.h"
//#include "RoomFile.h"

void Room::SetName(std::string name) {
  this->name = name;
}

Room::Room(const std::__cxx11::basic_string<char> &name) : name(name) {}

const std::string Room::GetName() const {
  return name;
}

int Room::GetUsersCount() const {
  return users_count;
}

const std::string &Room::GetCreatorName() const {
  return creator_name;
}

Room::Room(const std::string &name, int users_count, const std::string &creator_name)
    : name(name), users_count(users_count), creator_name(creator_name) {}

void to_json(json& j, const Room& room) {
  j = json{
    {"name", room.name},
    {"users_count", room.users_count},
    {"creator_name", room.creator_name},
    };
}
void from_json(const json& j, Room& room) {
  j.at("name").get_to(room.name);
  j.at("users_count").get_to(room.users_count);
  j.at("creator_name").get_to(room.creator_name);
}

Room::Room() {

}
