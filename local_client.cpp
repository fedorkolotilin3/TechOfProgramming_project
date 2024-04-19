#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <thread>

class ServerListener {
  int CreateSocket;
 public:
  explicit ServerListener(int create_socket) : CreateSocket(create_socket) {}
  void Listen() {
    char dataReceived[1024];
    int n = 0;
    while((n = recv(CreateSocket, dataReceived, sizeof(dataReceived)-1, 0)) > 0)
    {
      dataReceived[n] = 0;
      std::cout << dataReceived << std::endl;
    }
  }
};

int main(int argc, char** argv)
{
//  std::cout << strlen("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  try {
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    std::cout << "port: " << argv[2] << std::endl;
    serverAddress.sin_port = htons(std::stoi(argv[2]));
    std::cout << "address: " << inet_addr(argv[1]) << std::endl;
    serverAddress.sin_addr.s_addr = inet_addr(argv[1]);

    int res = connect(clientSocket, (struct sockaddr*) &serverAddress,
                      sizeof(serverAddress));
    std::cout << "connection res: " << res << std::endl;
    std::thread ServListnThread(&ServerListener::Listen, ServerListener(clientSocket));
    ServListnThread.detach();
    std::string inp;
    std::cin >> inp;
    while (inp.data() != "!end") {
      const char* message = inp.data();
      send(clientSocket, message, strlen(message), 0);
      std::cin >> inp;
    }
    close(clientSocket);
  }
  catch (...) {
    close(clientSocket);
  }
  return 0;
}

//int main() {
//  struct addrinfo hints, *res;
//  int sockfd;
//
//  // first, load up address structs with getaddrinfo():
//
//  memset(&hints, 0, sizeof hints);
//  hints.ai_family = AF_UNSPEC;
//  hints.ai_socktype = SOCK_STREAM;
//
//  getaddrinfo("www.example.com", "3490", &hints, &res);
//
//  // make a socket:
//
//  sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
//
//  // connect!
//
//  connect(sockfd, res->ai_addr, res->ai_addrlen);
////  char *msg = "Beej was here!";
////  int len, bytes_sent;
////  len = strlen(msg);
////  bytes_sent = send(sockfd, msg, len, 0);
//}
