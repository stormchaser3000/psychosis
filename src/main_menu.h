#include <raylib.h>
#include <physac.h>

#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_


// create a class for the title screen text
class WelcomeText {
public:
  // declare the needed variables to store things like the position of the
  // welcome text
  Vector2 position;
  bool visible;
  Texture2D texture;

  // declare the constructor
  WelcomeText(float pos_x, float pos_y, bool is_shown);

  // declare the render() method
  void render();

  // declare the unload_texture() method
  void unload_texture();
};


// create a class for the main character in the main menu
class MainMenuCharacter {
public:
  // declare the needed variables to store things like the position and the
  // needed information for the character animation
  Texture2D texture;
  bool visible;
  Vector2 position;
  Rectangle frames;
  int current_frame;
  int frame_counter;
  int frame_speed;

  // declare the constructor
  MainMenuCharacter(float pos_x, float pos_y, bool is_shown);

  // declare the render() method
  void render();

  // declare the unload_texture() method
  void unload_texture();
};


// create a class for the start game button in the main menu
class StartGameButton {
public:
  Vector2 position;
  bool visible;
  Image image;
  Texture2D texture;

  StartGameButton(float pos_x, float pos_y, bool is_shown);
  void render();
  void unload_texture();
};


// create a class for the options button in the main menu
class OptionsButton {
public:
  // declare variables to store the position, weather or not the texture should
  // be drawn by the render() method, the image and the texture
  Vector2 position;
  bool visible;
  Image image;
  Texture2D texture;

  // declare the constructor (see main_menu.cpp for definition)
  OptionsButton(float pos_x, float pos_y, bool is_shown);

  // declare the render() method
  void render();

  // declare the unload_texture() method
  void unload_texture();
};

// declare the main_menu function
void main_menu();
#endif
