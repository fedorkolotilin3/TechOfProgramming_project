#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QUdpSocket>
#include <QTcpSocket>
#include <iostream>
#include "StartActivity.h"
#include "Application.h"
#include "FieldStructure.h"
#include "Room.h"
#include "RoomFile.h"
#include "GameServer.h"
#include "Player.h"
#include "GameClient.h"

void SetField() {
  FieldStructure f("Data/test_field.xml");
  auto vec = f.GetContent();
  vec.clear();
  for (int i = -4; i < 5; i++) {
    for (int j = -4; j < 5; j++) {
      if (abs(i - j) <= 4 && (i + j) % 3 == 0) {
        vec.push_back({HexType::Empty, {2 * i, 2 * j}});
      }
    }
  }
  FieldStructure f2("Data/test_field.xml");
  f2.SetContent(vec);
}

void GenerateRooms() {
  Room room("worst room", 6, "Bad Guy");
  RoomFile example("example.json");
  example.SetContent(room);
}

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  Application::Init();
  auto start_activity = new StartActivity;
  Application::AddWidget(start_activity->GetContainer());
  start_activity->Launch();
  Application::Exec();
  SetField();
  GenerateRooms();
  return app.exec();
}

int main1(int argc, char* argv[]) {
  std::string arg1 = argv[1];
  if (arg1 == std::string("client")) {
    GameClient client;
    client.ListenRooms();
  }
  else {
    GameServer server;
    server.StartFindingPlayers(argv[2]);
  }
}