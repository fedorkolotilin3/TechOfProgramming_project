#include <QtCore>
#include <QtGui>
#include <QObject>
#include <QtWidgets>
#include <View.cpp>
#include <MainMenu.cpp>
#include <QMessageBox>
#include "Button.cpp"

void onClick();

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  QWidget* main_menu = new QWidget;
  Button* button = new Button(main_menu);
  button->SetText("press me");
  button->SetGeometry(200, 200, 100, 30);
  main_menu->show();
  return app.exec();
}
void onClick()
{
  QMessageBox msgBox;     // диалоговое окно
  msgBox.setText("Hello METANIT.COM!"); // устанавливаем текст
  msgBox.exec();  // отображаем диалоговое окно
}