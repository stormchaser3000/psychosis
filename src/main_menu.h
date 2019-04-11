#include <raylib.h>
#include <physac.h>

#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_



class WelcomeText {
public:
  Vector2 position;
  bool visible;
  Font font;

  WelcomeText(float pos_x, float pos_y, bool is_shown);
  void render()
};



class MainMenuCharacter {
  // character is 32x48 pixels
public:
  Texture2D texture;
  bool visible;
  Vector2 position;
  Rectangle frames;
  int current_frame;
  int frame_counter;
  int frame_speed;

  MainMenuCharacter(float pos_x, float pos_y, bool is_shown);
  void render();
  void unload_texture();
};



class StartGameButton {
public:
  Vector2 position;
  bool visible;
  Image image;
  Texture2D texture;

  StartGameButton(float pos_x, float pos_y, bool is_shown);
  void render()
  void unload_texture();
};



class OptionsButton {
public:
  Vector2 position;
  bool visible;
  Image image;
  Texture2D texture;

  OptionsButton(float pos_x, float pos_y, bool is_shown);
  void render();
  void unload_texture();
};
#endif
