#include <iostream>
#include "main_menu.h"


// define WelcomeText member functions

// define the welcome text constructor
WelcomeText::WelcomeText(float pos_x, float pos_y, bool is_shown) {
  // set the position of the Welcome text
  position.x = pos_x - 133;
  position.y = pos_y - 25;

  // set weather or not the welcome text is shown
  visible = is_shown;

  // load the texture of the welcome text into memory
  texture = LoadTexture("assets/psychosis title.png");
}

// create a function that renders the welcome text on the screen
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
/*
StartGameButton::StartGameButton(float pos_x, float pos_y, bool is_shown, std::string *level) {

}
*/
