#include <raylib.h>
#include <physac.h>

#ifndef _MAIN_MENU_H_
#define _MAIN_MENU_H_



class WelcomeText {
public:
  Vector2 position;
  bool visible;

  WelcomeText(int pos_x, int pos_y, bool is_shown);
  void render()
};



class MainMenuCharacter {
  // character is 32x48 pixels
public:
  Image image;
  Texture2D texture;
  bool visible;
  Vector2 position;

  MainMenuCharacter(int pos_x, int pos_y, bool is_shown);
  void render();
};



class StartGameButton {
public:
  Vector2 position;
  bool visible;
  Image image;
  Texture2D texture;

  StartGameButton(int pos_x, int pos_y, bool is_shown);
  void render()
};



class OptionsButton {
public:
  Vector2 position;
  bool visible;
  Image image;
  Texture2D texture;

  OptionsButton(int pos_x, int pos_y, bool is_shown);
  void render()
};
#endif
