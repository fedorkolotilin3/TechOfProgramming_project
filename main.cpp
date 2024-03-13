#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include "StartActivity.cpp"
//#include "Button.cpp"
//#include "MainMenu.cpp"
//#include "PlayMenu.cpp"
//#include "Activity.cpp"
//#include "Widget.cpp"

int main(int argc, char* argv[]) {
  StartActivity app(argc, argv);
  return app.Launch();
}