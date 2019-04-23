#include <iostream>
#include <string>
#include "dungeons.h"

Level1::Level1() {
  section_one.width = 5;
  section_one.height = 5;
  position.x = (GetScreenWidth() / 2) - 40;
  position.y = (GetScreenHeight() / 2) - 40;
}

void Level1::render(std::string *level) {
  if (IsKeyDown(KEY_LEFT)) {
    position.x -= 8;
  } else if (IsKeyDown(KEY_RIGHT)) {
    position.x += 8;
  }

  if (IsKeyDown(KEY_UP)) {
    position.y -= 8;
  } else if (IsKeyDown(KEY_DOWN)) {
    position.y += 8;
  }

  if (*level == "level1") {
    
  }
}
