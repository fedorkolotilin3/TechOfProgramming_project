#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include "StartActivity.h"
//#include "Button.cpp"
//#include "MainMenu.cpp"
//#include "PlayMenu.cpp"
//#include "Activity.cpp"
//#include "Widget.cpp"

int main(int argc, char* argv[]) {
  StartActivity app(argc, argv);
//  QApplication app(argc, argv);
//  auto main_menu = new QWidget;
//  auto layout = new QVBoxLayout;
//  auto text1 = new QLabel("text1");
//  auto text2 = new QLabel("text2");
//  layout->addWidget(text1, 1, Qt::AlignHCenter);
//  layout->addWidget(text2, 1, Qt::AlignHCenter);
//  main_menu->setLayout(layout);
//  main_menu->showMaximized();
//  return app.exec();
  return app.Launch();
}