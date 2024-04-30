#include <iostream>
#include "GameClient.h"
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void GameClient::ListenRooms() {
  int bufer_len = 100;
  int sockfd;
  int numbytes;
  struct sockaddr_storage their_addr;
  char buf[bufer_len];
  socklen_t addr_len;
  char addr_str[INET_ADDRSTRLEN];

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(12345);
  addr.sin_addr.s_addr = INADDR_ANY;
  int bind_res = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
  int i = 0;
  while (true) {
//    std::cout << std::endl;
    std::vector<std::string> rooms_to_delete;
//    std::cout << "room list" << std::endl;
    for (auto pair : servers) {
//      std::cout << pair.second.first << ".s " << pair.second.second << std::endl;
      auto cur_time = std::clock();
      if ((cur_time - pair.second.first) > 500) {
        rooms_to_delete.push_back(pair.first);
      }
    }
    for (auto x : rooms_to_delete) {
      DeleteRoom(x);
    }
    addr_len = sizeof their_addr;
//    int timeout_value = 4;
    struct timeval timeout;
    timeout.tv_sec = 4;
    timeout.tv_usec = 0;
//    tv.tv_sec = 5;
    int res = setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO,(struct timeval *)&timeout,sizeof(struct timeval));

    numbytes = recvfrom(sockfd, buf, bufer_len-1 , 0,
                        (struct sockaddr *)&their_addr, &addr_len);
    if (numbytes == -1) {
      continue;
    }
    buf[numbytes] = '\0';
    std::string inp_addr = inet_ntop(their_addr.ss_family,
                                     &(((struct sockaddr_in*)((struct sockaddr *)&their_addr))->sin_addr),
                                    addr_str, sizeof addr_str);
    if (!servers.contains(inp_addr)) {
      AddRoom(inp_addr, Room::from_json(buf));
    }
    servers[inp_addr] = {std::clock(), Room::from_json(buf)};
  }
  close(sockfd);
}

void GameClient::AddRoom(std::string ip, const Room& room) {
  AddRoomS(room.to_json().data());
//  AddRoomS();
  servers.insert({ip, {std::clock(), room}});
}

void GameClient::DeleteRoom(std::string ip) {
  Room room_to_delete = servers[ip].second;
  DeleteRoomS(room_to_delete.to_json().data());
//  DeleteRoomS();
  servers.erase(ip);
}


//return &(((struct sockaddr_in*)sa)->sin_addr);
//
//void get_in_addr() {}