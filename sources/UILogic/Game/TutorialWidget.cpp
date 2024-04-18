#include <QScrollArea>
#include <QMainWindow>
#include <QGraphicsScene>
#include "TutorialWidget.h"
#include "TextWidget.h"
#include "Button.h"
#include "ScrollArea.h"
#include "GameMenuWidget.h"

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
  auto container_layout = new QVBoxLayout(this);
  container = new Widget(this);
  //  container->setStyleSheet("background: red");
  container_layout->addWidget(container);
  auto layout = new QGridLayout(container);
  auto fieldWidget = new GameFieldWidget;
  layout->addWidget(fieldWidget, 0, 0, 6, 6);
  auto text1 = new TextWidget("other players && chat");
  auto text2 = new TextWidget("your buildings and actions");
  auto text3 = new TextWidget("your info such as resources count");
  auto button = new Button();
  button->SetText("reload field");
  button->SetAction([fieldWidget] {
    fieldWidget->field.ShuffleHexes();
    fieldWidget->field = GameField(fieldWidget->x() + fieldWidget->width() / 2, fieldWidget->y() + fieldWidget->height() / 2);
    fieldWidget->repaint();
  });
  text1->setFrameStyle(QFrame::Panel | QFrame::Raised);
  text2->setFrameStyle(QFrame::Panel | QFrame::Raised);
  text3->setFrameStyle(QFrame::Panel | QFrame::Raised);
  layout->addWidget(text1,0, 6, 5, 1, Qt::AlignCenter);
  layout->addWidget(text2, 6,  0, 1, 6, Qt::AlignCenter);
  layout->addWidget(text3,6, 6, Qt::AlignCenter);
  layout->addWidget(button, 5, 6, Qt::AlignCenter);
  auto menu_button = new Button(container);
  menu_button->SetGeometry(0, 0, 60, 60);
  menu_button->SetIconBFN("../Data/Icons/menu_icon.png");
  menu_button->SetIconFullSize();
  game_menu = new GameMenuWidget(this, this);
  //  game_menu->setSize;
  game_menu->hide();
  menu_button->SetAction([this]()->void {
    if (!is_menu_active) {
      this->container->setEnabled(false);
      //      game_menu->setEnabled(true);
      game_menu->setFixedSize(150, this->height());
      game_menu->show();
      is_menu_active = true;
    }
  });
}

void TutorialWidget::OnExit() {
}

TutorialWidget::TutorialWidget(Widget* parent) : Widget(parent) {
  OnCreate();
}

TutorialWidget::TutorialWidget() : Widget() {
  OnCreate();
}

void TutorialWidget::mousePressEvent(QMouseEvent* event) {
  if (is_menu_active) {
    if (game_menu->geometry().contains(event->pos())) {
      return;
    }
    is_menu_active = false;
    game_menu->hide();
    container->setEnabled(true);
    return;
  }
  QWidget::mousePressEvent(event);
}
