//
// Created by fedorkolotilin on 13.03.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_UICLASSES_BUTTON_H_
#define TP_PROJECT_FIODORKOLOTILIN_UICLASSES_BUTTON_H_

#include <QPushButton>
#include <Widget.h>

class Button : public Widget {
  QPoint start_vector;
  QVBoxLayout* layout;
  QPushButton* button;
 public:
  void SetText(std::string text);
 protected:
  void changeEvent(QEvent* event) override;
 public:
  void SetIcon(QIcon& icon);
  void SetIconSize(int width, int height);
  void SetIconFullSize();
  void SetIconBFN(std::string file_path);
  void SetAction(auto function)  {
    QObject::connect(button, &QPushButton::clicked, function);
  }
  //  void SetPosition(int x, int y);
  //  void SetGeometry(int x, int y, int wight, int height);
  //  void SetRelative(QPoint point);
  //  void SetRelativeToCenter();
  Button(Widget* parent);
  Button();
  Widget* GetSelfWidget();
  QPushButton* GetSelfButton();
};

#endif //TP_PROJECT_FIODORKOLOTILIN_UICLASSES_BUTTON_H_
