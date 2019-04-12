#include <iostream>
#include <raylib.h>
#include <physac.h>
#include "main_menu.h"



// define the main function
int main() {
  // set the window size
  int scr_width = 800;
  int scr_height = 600;

  // initialize the game window
  InitWindow(scr_width, scr_height, "RPG");

  // set the target frame rate to 60
  SetTargetFPS(60);

  // start the game by calling the main_menu function
  main_menu();

  // close the window after the game has ended
  CloseWindow();

  // successfully close the program by returning 0
  return 0;
}
