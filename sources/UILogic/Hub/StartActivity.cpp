//
// Created by fedorkolotilin on 13.03.24.
//

#include "Activity.cpp"
#include "MainMenu.cpp"
#include "StartActivity.h"

int StartActivity::Launch()  {
  MainMenu* main_menu = new MainMenu;
  main_menu->Show();
  return this->Activity::Launch();
}
StartActivity::StartActivity(int &argc, char** argv) : Activity(argc, argv) {}