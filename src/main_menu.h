#include <string>
#include "object.h"

#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_


// create a class for the title screen text
class WelcomeText : public GameObject {
public:
  // declare the constructor
  WelcomeText(float pos_x, float pos_y, bool is_shown);

  // declare the render() method
  void render(std::string *level);

  // declare the unload_texture() method
  void unload_texture();
};


// create a class for the start game button in the main menu
/*
class StartGameButton : public GameObject {
public:
  StartGameButton(float pos_x, float pos_y, bool is_shown);
  void render();
  void unload_texture();
};
*/


// create a class for the options button in the main menu
/*
class OptionsButton : GameObject {
public:
  // declare the constructor (see main_menu.cpp for definition)
  OptionsButton(float pos_x, float pos_y, bool is_shown);

  // declare the render() method
  void render();

  // declare the unload_texture() method
  void unload_texture();
};
*/
#endif
