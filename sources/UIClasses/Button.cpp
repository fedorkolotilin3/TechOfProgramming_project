//
// Created by fedorkolotilin on 13.03.24.
//
#include "Button.h"

void Button::SetText(std::string text) {
  QString q_text(text.data());
//  this->orogin_button->setText(q_text);
  this->setText(q_text);
}
void Button::SetPosition(int x, int y) {
//  this->orogin_button->move(x, y);
  this->move(x, y);
}
void Button::SetGeometry(int x, int y, int wight, int height) {
//  this->orogin_button->setGeometry(x, y, wight, height);
  this->setGeometry(x, y, wight, height);
}
Button::Button(QWidget* parent) : QPushButton(parent){
}