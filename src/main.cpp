#include <iostream>
#include <string>
#include <raylib.h>
#include <physac.h>
#include "main_menu.h"
#include "characters.h"



// define the main function
int main() {
  // set the window size
  int scr_width = GetScreenWidth();
  int scr_height = GetScreenHeight();

  // initialize the game window
  InitWindow(scr_width, scr_height, "RPG");
  
  // put the window into fullscreen
  ToggleFullscreen();

  // set the target frame rate to 60
  SetTargetFPS(60);

  // initialize the physics engine
  //InitPhysics();

  // set the level to "main menu"
  std::string level = "main menu";
  bool game_starting = true;

  // initialize the characters
  WelcomeText welcome_text(GetScreenWidth() / 2, 100, true);
  MainCharacter main_character((GetScreenWidth() / 2), (GetScreenHeight() / 2), true);
  StartGameButton start_button((GetScreenWidth() / 2), (GetScreenHeight() - 100));
//  StartGameButton start_button();


  // start the main loop
  while (!WindowShouldClose()) {
    // render all the things
    BeginDrawing();
      ClearBackground(BLACK);
      welcome_text.render(&level);
      main_character.render(&level, &game_starting);
      start_button.render(&level, &game_starting);
    EndDrawing();
  }

  // shut down the physics engine
  //ClosePhysics();

  // close the window after the game has ended
  CloseWindow();

  // successfully close the program by returning 0
  return 0;
}
