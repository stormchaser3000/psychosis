#include <iostream>
#include <raylib.h>
#include <physac.h>
#include "main_menu.h"

int main() {
  int scr_width = 800;
  int scr_height = 600;

  InitWindow(scr_width, scr_height, "RPG");

  SetTargetFPS(60);

  main_menu();
}
