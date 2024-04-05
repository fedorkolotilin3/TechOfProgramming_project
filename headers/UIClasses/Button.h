//
// Created by fedorkolotilin on 13.03.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_UICLASSES_BUTTON_H_
#define TP_PROJECT_FIODORKOLOTILIN_UICLASSES_BUTTON_H_

#include <QPushButton>
#include <Widget.h>

class Button : public Widget, public QPushButton {
  QPoint start_vector;
 public:
  void SetText(std::string text);
  void SetAction(auto function);
//  void SetPosition(int x, int y);
//  void SetGeometry(int x, int y, int wight, int height);
//  void SetRelative(QPoint point);
//  void SetRelativeToCenter();
  Button(Widget* parent);
  Button() = default;
  Widget* GetSelfWidget();
  QPushButton* GetSelfButton();
};

#endif //TP_PROJECT_FIODORKOLOTILIN_UICLASSES_BUTTON_H_
