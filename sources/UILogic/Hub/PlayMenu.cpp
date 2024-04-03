//
// Created by fedorkolotilin on 14.03.24.
//

#include "PlayMenu.h"
#include "Button.h"
#include "Widget.h"
#include "MainMenu.h"
#include "TutorialActivity.h"
#include "Application.h"

void PlayMenu::OnCreate() {
  auto layout = new QVBoxLayout(this);
  start_tutorial.SetText("start tutorial");
  start_tutorial.SetAction([this]{
    auto tutorial_activity = new TutorialActivity;
    Application::AddWidget(tutorial_activity->GetContainer());
    tutorial_activity->Launch();
    auto  parent = this->parentWidget()->layout()->parentWidget();
    Application::DeleteWidget(parent);
    parent->deleteLater();
//    this->GetParent()->deleteLater();
  });
  start_global_game.SetText("start global game");
  start_local_game.SetText("start local game");
  exit.SetText("exit");
  exit.SetAction([this]{
    Widget::ChangeWidget(this, new MainMenu);
  });
  layout->addWidget(start_tutorial.GetSelfButton(), 0, Qt::AlignHCenter);
  layout->addWidget(start_global_game.GetSelfButton(), 0, Qt::AlignHCenter);
  layout->addWidget(start_local_game.GetSelfButton(), 0, Qt::AlignHCenter);
  layout->addWidget(exit.GetSelfButton(), 0, Qt::AlignHCenter);
}

PlayMenu::PlayMenu(){
  OnCreate();
}

PlayMenu::PlayMenu(Widget* widget) {
  setParent(widget);
  OnCreate();
}
