#include <iostream>
#include <string>
#include <raylib.h>
#include <physac.h>
#include "main_menu.h"
#include "characters.h"



// define the main function
int main() {
  // set the window size
  int scr_width = 800;
  int scr_height = 600;

  // initialize the game window
  InitWindow(scr_width, scr_height, "RPG");

  // set the target frame rate to 60
  SetTargetFPS(60);

  // initialize the physics engine
  //InitPhysics();

  // set the level to "main menu"
  std::string level = "main menu";

  // initialize the characters
  WelcomeText welcome_text(400, 100, true);
  MainCharacter main_character((GetScreenWidth() / 2), (GetScreenHeight() / 2), true);
//  StartGameButton start_button();


  // start the main loop
  while (!WindowShouldClose()) {
    // render all the things
    BeginDrawing();
      ClearBackground(BLACK);
      welcome_text.render(&level);
      main_character.render(&level);
    EndDrawing();
  }

  // shut down the physics engine
  //ClosePhysics();

  // close the window after the game has ended
  CloseWindow();

  // successfully close the program by returning 0
  return 0;
}
