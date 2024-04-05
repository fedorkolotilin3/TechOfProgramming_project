//
// Created by fedorkolotilin on 23.03.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_HEADERS_UILOGIC_APPLICATION_H_
#define TP_PROJECT_FIODORKOLOTILIN_HEADERS_UILOGIC_APPLICATION_H_

#include "Widget.h"

class Application {
 private:
  inline static Application* instance = nullptr;
  Widget* widget_container;
  Application();
 public:
  static Application* GetInstacne();
  static void Exec();
  static void AddWidget(Widget* new_widget);
  static void AddWidget(QWidget* new_widget);
  static void ChangeWidget(Widget* prev, Widget* next);
  static void ChangeWidget(QWidget* prev, QWidget* next);
  static Widget* DeleteWidget(Widget* widget_to_delete);
  static QWidget* DeleteWidget(QWidget* widget_to_delete);
  static void Init();
};
#endif //TP_PROJECT_FIODORKOLOTILIN_HEADERS_UILOGIC_APPLICATION_H_
