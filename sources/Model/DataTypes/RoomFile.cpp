#include <iostream>
#include "RoomFile.h"

RoomFile::RoomFile(const std::string &source_path) : File(source_path) {}

Room RoomFile::GetContent() {
  std::ifstream i_file("../Data/Rooms/" + source_path);
  json j_data = json::parse(i_file);
  Room room;
  j_data.get_to(room);
  i_file.close();
  return room;
}

void RoomFile::SetContent(Room room) {
  std::ofstream o_file("../Data/Rooms/" + source_path);
//  o_file.clear();
  json j_data(room);
  std::string dump = j_data.dump();
  o_file << j_data.dump();
  std::cerr << j_data.dump();
  o_file.close();
}
