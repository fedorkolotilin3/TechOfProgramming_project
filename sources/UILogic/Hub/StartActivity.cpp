//
// Created by fedorkolotilin on 13.03.24.
//

#include "Activity.h"
#include "MainMenu.h"
#include "StartActivity.h"

int StartActivity::Launch()  {
//  widget_container->ShowMaximized();
  return this->Activity::Launch();
}
StartActivity::StartActivity() {
  layout = new QVBoxLayout;
  widget_container = new Widget;
  MainMenu* main_menu = new MainMenu;
  layout->addWidget(main_menu);
  widget_container->SetLayout(layout);
}
