//
// Created by fedorkolotilin on 14.03.24.
//

#include "PlayMenu.h"
#include "Button.cpp"
#include "Widget.h"
//#include "MainMenu.cpp"

PlayMenu::PlayMenu() :
  start_global_game(this),
  start_local_game(this),
  exit(this) {
  start_global_game.SetPosition(300, 100);
  start_global_game.SetText("start global game");
  start_local_game.SetPosition(300, 400);
  start_local_game.SetText("start local game");
  exit.SetPosition(300, 700);
  exit.SetText("exit");
  exit.SetAction([this]{
    auto main_menu = new MainMenu;
    main_menu->Show();
    this->Hide();
  });
}