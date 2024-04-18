//
// Created by fedorkolotilin on 10.04.24.
//
#include "GameMenuWidget.h"
#include "Button.h"
#include "MainMenu.h"
#include "TextWidget.h"
#include "iostream"

GameMenuWidget::GameMenuWidget(Widget* base_widget) : Widget() {
  this->base_widget = base_widget;
  OnCreate();
}

GameMenuWidget::GameMenuWidget(Widget* base_widget, Widget* widget) : Widget(widget) {
  this->base_widget = base_widget;
  OnCreate();
}

void GameMenuWidget::OnCreate() {
  auto layout = new QVBoxLayout(this);
  auto exit_button = new Button;
  exit_button->SetText("Exit");
  exit_button->SetAction([this]()->void{
    this->base_widget->ChangeWidget(new MainMenu());
  });
  layout->addWidget(exit_button);
  for (int i = 0; i < 4; i++) {
    auto text_i = new TextWidget("item " + std::to_string(i + 1));
    layout->addWidget(text_i);
  }
  setAutoFillBackground(true);
}

void GameMenuWidget::resizeEvent(QResizeEvent* resize_event) {
  std::cerr << "resize\n";
  setFixedSize(150, parentWidget()->height());
  Widget::resizeEvent(resize_event);
}

