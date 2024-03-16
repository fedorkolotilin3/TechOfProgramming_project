//
// Created by fedorkolotilin on 13.03.24.
//

#include "Activity.h"

int Activity::Launch() {
  return this->exec();
}
Activity::Activity(int& argc, char** argv) : QApplication(argc, argv) {}
