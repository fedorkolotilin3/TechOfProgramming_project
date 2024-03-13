//
// Created by fedorkolotilin on 13.03.24.
//
#include "MainMenu.h"
#include "PlayMenu.cpp"
#include "Widget.cpp"

MainMenu::MainMenu() : play_button(this), settings_button(this){
  play_button.SetPosition(300, 100);
  play_button.SetText("Play");
  play_button.SetAction([this]{
    PlayMenu* play_menu = new PlayMenu;
    play_menu->Show();
    this->Hide();
  });
  settings_button.SetPosition(300, 400);
  settings_button.SetText("Settings");
}