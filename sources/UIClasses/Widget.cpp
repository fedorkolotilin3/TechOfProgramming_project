#include "Widget.h"
#include <QDialog>
#include <QLabel>
#include <QResizeEvent>
#include <QScreen>
#include <QGuiApplication>

void Widget::SetName(std::string name) {
  widget_name = name;
}

void Widget::resizeEvent(QResizeEvent* resize_event) {
//  QSize old_size = resize_event->oldSize();
//  QSize new_size = resize_event->size();
//  double diff_x = new_size.width();
//  diff_x /= old_size.width();
//  double diff_y = new_size.height();
//  diff_y /= old_size.height();
//  double this_height = this->height();
//  double this_width = this->width();
//  if (new_size != size()) {
//    this->setGeometry(geometry().x(), geometry().y(), this_height *= diff_x, this_height *= diff_y);
//  }
}
void Widget::Show() {
  return this->show();
}
void Widget::ShowMaximized() {
  return this->showMaximized();
}
void Widget::Hide() {
  return this->hide();
}
void Widget::Maximize() {
  if (parent == nullptr) {
    this->setFixedHeight(QGuiApplication::screenAt({0, 0})->geometry().height() - 100);
    this->setFixedWidth(QGuiApplication::screenAt({0,0})->geometry().width() - 50);
    return;
  }
  this->setFixedHeight(parent->maximumHeight());
  this->setFixedWidth(parent->maximumWidth());
//  this->setFixedHeight(this->frameGeometry().width());
//  this->setFixedWidth(this->frameGeometry().height());
}
void Widget::SetPosition(int x, int y) {
//  this->move(position + this->start_vector);
  this->move(x + start_vector.x(), y + start_vector.y());
}
void Widget::SetGeometry(int x, int y, int wight, int height) {
  this->setGeometry(x + this->start_vector.x(), y + this->start_vector.y(), wight, height);
}
void Widget::SetRelative(QPoint point) {
  this->start_vector = point;
}
void Widget::SetRelativeToCenter() {
  this->SetRelative(-GetCenter());
}
QPoint Widget::GetCenter() {
  return {this->width() / 2, this->height() / 2};
}
Widget::Widget(Widget* parent) : parent(parent), QWidget(parent), start_vector(0, 0) {}
Widget::Widget(): QWidget(), start_vector(0, 0) {
}

Widget* Widget::GetParent() {
  return parent;
}

void Widget::SetParent(Widget* parent) {
  this->parent = parent;
  setParent(parent);
}

void Widget::SetLayout(QLayout* layout) {
  this->layout = layout;
  setLayout(layout);
}

QLayout* Widget::GetLayout() {
  return this->layout;
}

void Widget::ChangeWidget(Widget* prev, Widget* next) {
  auto pointer = (prev->parentWidget()->layout()->replaceWidget(prev, next));
  pointer->widget()->deleteLater();
}

void Widget::ChangeWidget(Widget* next) {
  ChangeWidget(this, next);
}
