//
// Created by fedorkolotilin on 13.03.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_UICLASSES_BUTTON_H_
#define TP_PROJECT_FIODORKOLOTILIN_UICLASSES_BUTTON_H_

#include <QAbstractButton>
#include <QPushButton>

class Button : public QPushButton {
 private:
  QPushButton* orogin_button;
 public:
  int counter = 0;
  void SetText(std::string text);
  void SetPosition(int x, int y);
  void SetGeometry(int x, int y, int wight, int height);
  void SetAction(auto function);
  Button(QWidget* parent);
};

#endif //TP_PROJECT_FIODORKOLOTILIN_UICLASSES_BUTTON_H_
