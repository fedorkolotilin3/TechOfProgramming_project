//
// Created by fedorkolotilin on 13.03.24.
//
#include "Button.h"

void Button::SetText(std::string text) {
  QString q_text(text.data());
//  this->orogin_button->setText(q_text);
  this->setText(q_text);
}
//void Button::SetPosition(int x, int y) {
//  //  this->move(position + this->start_vector);
//  this->move(x + start_vector.x(), y + start_vector.y());
//}
//void Button::SetGeometry(int x, int y, int wight, int height) {
//  this->setGeometry(x + this->start_vector.x(), y + this->start_vector.y(), wight, height);
//}
//void Button::SetRelative(QPoint point) {
//  this->start_vector = point;
//}
//void Button::SetRelativeToCenter() {
//  this->SetRelative({-this->width() / 2, -this->height() / 2});
//}
Button::Button(Widget* parent) : Widget(parent) {
  this->Button::QPushButton::setParent(dynamic_cast<Widget*>(this));
}

Widget* Button::GetSelfWidget() {
  return dynamic_cast<Widget*>(this);
}

QPushButton* Button::GetSelfButton() {
  return dynamic_cast<Button*>(this);
}
