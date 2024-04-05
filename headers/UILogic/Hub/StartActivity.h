//
// Created by fedorkolotilin on 13.03.24.
//

#ifndef TP_PROJECT_FIODORKOLOTILIN_UILOGIC_HUB_STARTACTIVITY_H_
#define TP_PROJECT_FIODORKOLOTILIN_UILOGIC_HUB_STARTACTIVITY_H_

#include "Activity.h"
#include "Widget.h"
#include "MainMenu.h"

class StartActivity : public Activity{
 private:
  MainMenu* main_menu;
 public:
   int Launch();
   StartActivity(int& argc, char** argv);
   StartActivity();
};

#endif //TP_PROJECT_FIODORKOLOTILIN_UILOGIC_HUB_STARTACTIVITY_H_
