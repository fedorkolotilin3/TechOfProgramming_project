//
// Created by fedorkolotilin on 07.04.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_DATATYPES_ROOMFILE_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_DATATYPES_ROOMFILE_H_
#include "File.h"
#include "Room.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;

class RoomFile : public File {
 public:
  void SetContent(Room room);
  Room GetContent();
  RoomFile(const std::string &source_path);
};
#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_MODEL_DATATYPES_ROOMFILE_H_
