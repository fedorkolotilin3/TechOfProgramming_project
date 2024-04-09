//
// Created by fedorkolotilin on 13.03.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_UICLASSES_WIDGET_H_
#define TP_PROJECT_FIODORKOLOTILIN_UICLASSES_WIDGET_H_

#include <QWidget>
#include <QtGui>
#include <QtCore>
#include <Layout.h>

class Widget : /*public View,*/ public QWidget {
  std::string widget_name;
  QPoint start_vector;
  Widget* parent;
  QLayout* layout_;
 protected:
  void resizeEvent(QResizeEvent* resize_event) override;
 public:
  void SetName(std::string name);
  void Show();
  void ShowMaximized();
  void Hide();
  void SetPosition(int x, int y);
  void Maximize();
  void SetGeometry(int x, int y, int wight, int height);
  void SetRelative(QPoint point);
  void SetRelativeToCenter();
  QPoint GetCenter();
  Widget(Widget* parent);
  Widget();
  Widget* GetParent();
  void SetParent(Widget* parent);
  void SetLayout(QLayout* layout);
  QLayout* GetLayout();
  static void ChangeWidget(Widget* prev, Widget* next);
  static void ChangeWidget(QWidget* prev, QWidget* next);
  void ChangeWidget(Widget* next);
};

#endif //TP_PROJECT_FIODORKOLOTILIN_UICLASSES_WIDGET_H_
