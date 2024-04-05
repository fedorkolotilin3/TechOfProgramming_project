//
// Created by fedorkolotilin on 13.03.24.
//
#ifndef TP_PROJECT_FIODORKOLOTILIN_UICLASSES_ACTIVITY_H_
#define TP_PROJECT_FIODORKOLOTILIN_UICLASSES_ACTIVITY_H_

#include <QApplication>
#include <QLayout>
#include "Widget.h"

class Activity {
 protected:
  QLayout* layout;
  Widget* widget_container;
 public:
  int Launch();
  Activity(int& argc, char** argv);
  Activity();
  Widget* GetContainer();
};


#endif //TP_PROJECT_FIODORKOLOTILIN_UICLASSES_ACTIVITY_H_
