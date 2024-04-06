#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include "StartActivity.h"
#include "Application.h"
#include "FieldStructure.h"

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
//  vec.push_back({Hex(HexType::Empty), {6, 6}});
//  vec.push_back({Hex(HexType::Empty), {2, 4}});
//  vec.push_back({Hex(HexType::Empty), {4, 2}});
//  vec.push_back({Hex(HexType::Empty), {0, 0}});
//  vec.push_back({Hex(HexType::Empty), {-6, -6}});
//  vec.push_back({Hex(HexType::Empty), {-2, -4}});
//  vec.push_back({Hex(HexType::Empty), {-4, -2}});
//  vec.push_back({Hex(HexType::Empty), {-2, 2}});
//  vec.push_back({Hex(HexType::Empty), {2, -2}});
//  vec.push_back({Hex(HexType::Empty), {-4, 4}});
//  vec.push_back({Hex(HexType::Empty), {4, -4}});
//  vec.push_back({Hex(HexType::Empty), {-4, -2}});
  FieldStructure f2("Data/test_field.xml");
  f2.SetContent(vec);
}

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  Application::Init();
  auto start_activity = new StartActivity;
  Application::AddWidget(start_activity->GetContainer());
  start_activity->Launch();
  Application::Exec();
  SetField();
  return app.exec();
}