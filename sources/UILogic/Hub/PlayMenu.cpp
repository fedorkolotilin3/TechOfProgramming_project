//
// Created by fedorkolotilin on 14.03.24.
//

#include <QLabel>
#include "PlayMenu.h"
#include "Button.h"
#include "Widget.h"
#include "MainMenu.h"
#include "TutorialActivity.h"
#include "Application.h"

Widget* LocalGameWidgetCreate() {
  auto widget = new Widget();
  widget->setLayout(new QHBoxLayout());
  auto widget_label = new QLabel();
  auto widget_create = new Button();
  auto widget_join = new Button();
  widget_label->setText("local game:");
  widget_create->SetText("create game");
  widget_join->SetText("join game");
  widget->layout()->addWidget(widget_label);
  widget->layout()->addItem(new QSpacerItem(30, 0));
  widget->layout()->addWidget(widget_create->GetSelfButton());
  widget->layout()->addWidget(widget_join->GetSelfButton());
  return widget;
}

Widget* GlobalGameWidgetCreate() {
  auto widget = new Widget();
  widget->setLayout(new QHBoxLayout());
  auto widget_label = new QLabel();
  auto widget_create = new Button();
  auto widget_join = new Button();
  widget_label->setText("global game:");
  widget_create->SetText("create game");
  widget_join->SetText("join game");
  widget->layout()->addWidget(widget_label);
  widget->layout()->addItem(new QSpacerItem(30, 0));
  widget->layout()->addWidget(widget_create->GetSelfButton());
  widget->layout()->addWidget(widget_join->GetSelfButton());
  return widget;
}

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
  });
  exit.SetText("exit");
  exit.SetAction([this]{
    Widget::ChangeWidget(this, new MainMenu);
  });
  layout->addSpacing(200);
  layout->addWidget(start_tutorial.GetSelfButton(), 1, Qt::AlignHCenter);
//  layout->addWidget(start_global_game.GetSelfButton(), 0, Qt::AlignHCenter);
  layout->addWidget(LocalGameWidgetCreate(), 1, Qt::AlignHCenter);
  layout->addWidget(GlobalGameWidgetCreate(), 1, Qt::AlignHCenter);
  layout->addWidget(exit.GetSelfButton(), 1, Qt::AlignHCenter);
  layout->setAlignment(Qt::AlignCenter);
  layout->addSpacing(300);
}

PlayMenu::PlayMenu(){
  OnCreate();
}

PlayMenu::PlayMenu(Widget* widget) {
  setParent(widget);
  OnCreate();
}
