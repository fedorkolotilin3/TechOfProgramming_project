//
// Created by fedorkolotilin on 13.03.24.
//
#include <QApplication>
#include <QLabel>
#include "MainMenu.h"
#include "PlayMenu.h"
#include "Widget.h"
#include "StartActivity.h"

MainMenu::MainMenu() {
  OnCreate();
}
MainMenu::MainMenu(Widget* widget) {
  SetParent(widget);
  OnCreate();
}

void MainMenu::OnCreate() {
  QVBoxLayout* layout = new QVBoxLayout;
  layout->setAlignment(layout, Qt::AlignHCenter);
  play_button.SetText("Play");
  play_button.SetAction([this]{
    PlayMenu* play_menu = new PlayMenu;
    StartActivity::ChangeWidget(this, play_menu);
  });
  layout->addWidget(play_button.GetSelfButton(), 0, Qt::AlignHCenter);
  layout->addWidget(settings_button.GetSelfButton(), 0, Qt::AlignHCenter);
  settings_button.SetText("Settings");
  SetLayout(layout);
}