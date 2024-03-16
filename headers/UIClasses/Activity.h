//
// Created by fedorkolotilin on 13.03.24.
//
#ifndef TP_PROJECT_FIODORKOLOTILIN_UICLASSES_ACTIVITY_H_
#define TP_PROJECT_FIODORKOLOTILIN_UICLASSES_ACTIVITY_H_

#include <QApplication>

class Activity : public QApplication {
 public:
  int Launch();
  Activity(int& argc, char** argv);
};


#endif //TP_PROJECT_FIODORKOLOTILIN_UICLASSES_ACTIVITY_H_
