#include <iostream>
#include "main_menu.h"


// define WelcomeText member functions

// define the welcome text constructor
WelcomeText::WelcomeText(float pos_x, float pos_y, bool is_shown) {
  // set the position of the Welcome text
  position.x = pos_x - 134;
  position.y = pos_y - 25;

  // set weather or not the welcome text is shown
  visible = is_shown;

  // load the texture of the welcome text into memory
  texture = LoadTexture("assets/Psychosis Title.png");
}

// create a function that renders the welcome text on the screen
// if level is equal to "main menu"
void WelcomeText::render(std::string *level) {
  if (*level == "main menu") {
    DrawTexture(texture, position.x, position.y, WHITE);
  }
}

// create a function that unloads the character texture
void WelcomeText::unload_texture() {
  UnloadTexture(texture);
}





// define the member functions for StartGameButton

// define the constructor
StartGameButton::StartGameButton(float pos_x, float pos_y) {
  position.x = pos_x - 62;
  position.y = pos_y - 25;
  visible = true;
  image = LoadImage("assets/Start Button.png");
}

void StartGameButton::render(std::string *level, bool *game_starting) {
  if (visible == true) {
    texture = LoadTextureFromImage(image);
    DrawTexture(texture, position.x, position.y, GRAY);
  }

  // detect if the mouse is touching the start button
  // if it is then check if the left mouse button is being clicked
  // if it is then set level to "level1" to start the game
  if (*level == "main menu") {
    if ((GetMouseX() >= position.x) && (GetMouseY() >= position.y)) {
      if ((GetMouseX() <= (position.x + 125)) && (GetMouseY() <= (position.y + 50))) {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
          *level = "level1";
          visible = false;
          *game_starting = true;
        }
      }
    }
  }
}

// create a method to unload the texture from memory
void StartGameButton::unload_texture() {
  UnloadTexture(texture);
}
