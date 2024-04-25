#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_NETWORK_GAMECLIENT_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_NETWORK_GAMECLIENT_H_

#include <vector>
#include "Room.h"

class GameClient {
//  std::vector<Room> rooms;
  std::unordered_map<std::string, std::pair<int, std::string>> servers;
 public:
  void ListenRooms();
  void AddRoom(std::string ip, std::string name);
  void DeleteRoom(std::string ip);
};
#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_NETWORK_GAMECLIENT_H_
