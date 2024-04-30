//
// Created by fedorkolotilin on 19.04.24.
//
#include <iostream>
#include <QThread>
#include <netdb.h>
#include "GameServer.h"
#include <sys/socket.h>

void GameServer::StartFindingPlayers(std::string str = "") {
  class PlayerFinder {
    Room* room;
//    int sock;
   public:
//    explicit PlayerFinder(int sock) : sock(sock) {}
    PlayerFinder() {}

    explicit PlayerFinder(Room* room) : room(room) {}

    void SendMessages() {
      while (true) {
        int sockfd;
        struct addrinfo hints, * servinfo, * p;
        int rv;
        int numbytes;

        memset(&hints, 0, sizeof hints);
        hints.ai_family = AF_INET; // set to AF_INET to use IPv4
        hints.ai_socktype = SOCK_DGRAM;

        rv = getaddrinfo("255.255.255.255", "12345", &hints, &servinfo);
        for (p = servinfo; p != NULL; p = p->ai_next) {
          if ((sockfd = socket(p->ai_family, p->ai_socktype,
                               p->ai_protocol)) == -1) {
            continue;
          }

          break;
        }
        int broadcast = 1;
        if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcast,
                       sizeof broadcast) == -1) {
          perror("setsockopt (SO_BROADCAST)");
          exit(1);
        }

        std::string msg = room->to_json();
        numbytes = sendto(sockfd, msg.data(), msg.size(), 0,
                               p->ai_addr, p->ai_addrlen);

        freeaddrinfo(servinfo);
        close(sockfd);
        sleep(1);
      }
    }
  };
  std::thread Finding(&PlayerFinder::SendMessages, PlayerFinder(&serv_room));
  Finding.join();
}

GameServer::GameServer(const Room &serv_room) : serv_room(serv_room) {}
