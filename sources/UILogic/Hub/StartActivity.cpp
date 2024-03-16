//
// Created by fedorkolotilin on 13.03.24.
//

#include "Activity.h"
#include "MainMenu.h"
#include "StartActivity.h"

int StartActivity::Launch()  {
  auto layout = new QVBoxLayout;
  auto widget_container = new Widget;
  MainMenu* main_menu = new MainMenu;
  layout->addWidget(main_menu);
  widget_container->SetLayout(layout);
  widget_container->ShowMaximized();
  return this->Activity::Launch();
}
StartActivity::StartActivity(int &argc, char** argv) : Activity(argc, argv) {}

void StartActivity::ChangeWidget(Widget* prev, Widget* next) {
  auto pointer = (prev->parentWidget()->layout()->replaceWidget(prev, next));
  pointer->widget()->deleteLater();
}
