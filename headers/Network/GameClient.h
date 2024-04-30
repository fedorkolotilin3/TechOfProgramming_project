#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_NETWORK_GAMECLIENT_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_NETWORK_GAMECLIENT_H_

#include <vector>
#include <QObject>
#include "Room.h"

class GameClient : public QObject{
  Q_OBJECT
//  std::vector<Room> rooms;
  std::unordered_map<std::string, std::pair<int, Room>> servers;
  signals:
    void AddRoomS(QString room);
//    void AddRoomS();
    void DeleteRoomS(QString room);
//    void DeleteRoomS();
 public:
  void ListenRooms();
  void AddRoom(std::string ip, const Room& room);
  void DeleteRoom(std::string ip);
};
#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_NETWORK_GAMECLIENT_H_
