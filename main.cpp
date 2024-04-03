#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include "StartActivity.h"
#include "Application.h"
#include "FieldStructure.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  Application::Init();
  auto start_activity = new StartActivity;
  Application::AddWidget(start_activity->GetContainer());
  start_activity->Launch();
  Application::Exec();
  FieldStructure f("Data/test_field.xml");
  auto vec = f.GetContent();
  FieldStructure f2("Data/test_field.txt");
  f2.SetContent(vec);

  return app.exec();
}