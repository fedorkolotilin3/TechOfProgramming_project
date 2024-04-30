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

Room::Room(const std::string &creator_name, const std::string &indx, const std::string &name, int users_count)
    : creator_name(creator_name), indx(indx), name(name), users_count(users_count) {}

void to_json(json& j, const Room& room) {
  j = json{
    {"name", room.name},
    {"indx", room.indx},
    {"users_count", room.users_count},
    {"creator_name", room.creator_name},
    };
}
void from_json(const json& j, Room& room) {
  j.at("name").get_to(room.name);
  j.at("indx").get_to(room.indx),
  j.at("users_count").get_to(room.users_count);
  j.at("creator_name").get_to(room.creator_name);
}

Room::Room() {

}

std::string Room::to_json() const {
  json j_data(*this);
  std::string dump = j_data.dump();
  return dump;
}

Room Room::from_json(std::string str) {
  json j_data = json::parse(str);
  Room room;
  j_data.get_to(room);
  return room;
}
