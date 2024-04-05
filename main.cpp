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
    for (int i = -2; i < 3; i++) {
      for (int j = -2; j < 3; j++) {
        if (i + j >= -2 && i + j <= 2) {
          vec.push_back({Hex::GetRandom(), {i, j}});
        }
      }
    }
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