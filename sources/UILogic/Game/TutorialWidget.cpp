#include <QScrollArea>
#include <QMainWindow>
#include "TutorialWidget.h"
#include "TextWidget.h"
#include "GameFieldWidget.h"

Widget* GenerateFieldWidget() {
  auto widget = new GameFieldWidget();
  return widget;
}

void TutorialWidget::OnCreate() {
//  scrollArea->setBackgroundRole(QPalette::Dark);
//  auto main_widget = new QMainWindow();
//  auto field_area = new QScrollArea();
//  auto field_picture = new QLabel();
//  field_picture->setScaledContents(true);
//  auto field_image = new QImage("../Description/game_field.png");
//  field_picture->setGeometry(0, 0, 2000, 2000);
//  field_picture->setPixmap(QPixmap::fromImage(*field_image));
//  double resize_k = 3;
//  field_picture->resize(field_picture->width() * resize_k, field_picture->height() * resize_k);
//  field_picture->setStyleSheet("QLabel { background-color : blue; }");
//  field_picture->setFrameStyle(QFrame::Panel);
//  field_picture->setStyleSheet("image: url(../Description/game_field.png)");
//  field_area->setWidget(field_picture);
//  main_widget->setCentralWidget(field_area);

  auto layout = new QGridLayout(this);
  layout->addWidget(GenerateFieldWidget(), 0, 0, 4, 4);
  auto text1 = new TextWidget("other players && chat");
  auto text2 = new TextWidget("your buildings and actions");
  auto text3 = new TextWidget("your info such as resources count");
  text1->setFrameStyle(QFrame::Panel | QFrame::Raised);
  text2->setFrameStyle(QFrame::Panel | QFrame::Raised);
  text3->setFrameStyle(QFrame::Panel | QFrame::Raised);
  layout->addWidget(text1,0, 4, 4, 1, Qt::AlignCenter);
  layout->addWidget(text2, 4,  0, 1, 4, Qt::AlignCenter);
  layout->addWidget(text3,4, 4, Qt::AlignCenter);
//  layout->set()
}

void TutorialWidget::OnExit() {
}

TutorialWidget::TutorialWidget(Widget* parent) : Widget(parent) {
  OnCreate();
}

TutorialWidget::TutorialWidget() : Widget() {
  OnCreate();
}
