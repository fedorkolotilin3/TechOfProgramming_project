#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>
#include <netdb.h>
#include <cstring>
#include <thread>
#include <vector>

int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
std::vector<std::vector<std::string>> messages;
std::string build_string(char* buffer, int length) {
  std::string ans;
  for (int i = 0; i < length; i++) {
    ans += buffer[i];
  }
  return ans;
}

class ClientReader {
  inline static int max_client_id = 0;
  int client_id;
  int clientSocket;
 public:
  ClientReader(int client_socket) : client_id(max_client_id), clientSocket(client_socket) {
    messages.push_back({});
    max_client_id += 1;
  }
  void operator()() {
    while (true) {
      char buffer[1024] = {0};
      int recv_res = recv(clientSocket, buffer, sizeof(buffer), 0);
      if (recv_res <= 0) {
        return;
      }
      if (build_string(buffer, 4) == "!get") {
        int user_ind = buffer[4] - '0';
        for (auto msg : messages[user_ind]) {
          send(clientSocket, msg.data(), std::strlen(msg.data()), 0);
          sleep(4);
        }
      }
      else {
        messages[client_id].push_back(build_string(buffer, recv_res));
      }
      std::cout << "Message from client" << client_id << ": " << buffer << std::endl;
    }
  }
};

int main(int argc, char* args[])
{
  sockaddr_in serverAddress;
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(std::stoi(args[1]));
  serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
  bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
  listen(serverSocket, 20);
  while (true){
    socklen_t serv_size = sizeof(serverAddress);
    int clientSocket = accept(serverSocket, (struct sockaddr*)&serverAddress, (&serv_size));
    std::thread ClientReaderThread(&ClientReader::operator(), ClientReader(clientSocket));
    ClientReaderThread.detach();
  }
  close(serverSocket);
}