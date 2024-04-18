//
// Created by fedorkolotilin on 13.03.24.
//
#include "Button.h"

void Button::SetText(std::string text) {
  QString q_text(text.data());
  //  this->orogin_button->setText(q_text);
  button->setText(q_text);
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
  layout = new QVBoxLayout(this);
  button = new QPushButton;
  //  button->setGeometry(this->geometry());
  layout->addWidget(button);
  //  this->setStyleSheet("background: red");
}
Button::Button() : Widget() {
  layout = new QVBoxLayout(this);
  button = new QPushButton;
  //  button->setGeometry(this->geometry());
  layout->addWidget(button);
  //  this->setStyleSheet("background: red");
}

Widget* Button::GetSelfWidget() {
  return static_cast<Widget*>(this);
}

QPushButton* Button::GetSelfButton() {
  return button;
}

void Button::SetIconBFN(std::string file_path) {
  QPixmap pixmap(file_path.data());
  QIcon icon;
  icon.addPixmap(pixmap, QIcon::Normal);
  icon.addPixmap(pixmap, QIcon::Disabled);
  SetIcon(icon);
}

void Button::SetIcon(QIcon& icon) {
  button->setIcon(icon);
}

void Button::SetIconSize(int width, int height) {
  button->setIconSize(QSize(width, height));
}

void Button::SetIconFullSize() {
  button->setIconSize(this->GetSelfWidget()->size() * 0.5);
}

void Button::changeEvent(QEvent* event) {
  QWidget::changeEvent(event);
}

