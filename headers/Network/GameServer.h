#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_NETWORK_GAMESERVER_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_NETWORK_GAMESERVER_H_

class GameServer {
 private:
  bool is_sending = true;
  int messageNo = 1;
 public:
  void StartFindingPlayers(std::string);
  void AddPlayer();
  void GetMessage();
  void SendMessages();
};

#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_NETWORK_GAMESERVER_H_
