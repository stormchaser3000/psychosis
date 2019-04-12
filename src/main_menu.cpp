#include <iostream>
#include "main_menu.h"



// define WelcomeText member functions
WelcomeText::WelcomeText(float pos_x, float pos_y, bool is_shown) {
  position.x = pos_x - 133;
  position.y = pos_y - 25;
  visible = is_shown;
  texture = LoadTexture("assets/psychosis title.png");
}

void WelcomeText::render() {
  DrawTexture(texture, position.x, position.y, WHITE);
}

void WelcomeText::unload_texture() {
  UnloadTexture(texture);
}



// define MainMenuCharacter member functions
MainMenuCharacter::MainMenuCharacter(float pos_x, float pos_y, bool is_shown) {
  position.x = pos_x;
  position.y = pos_y;
  visible = is_shown;
  texture = LoadTexture("assets/characters/Main Character.png");
  frames.x = 0.0f;
  frames.y = 0.0f;
  frames.width = (float)texture.width/4;
  frames.height = (float)texture.height/4;
  current_frame = 0;
  frame_counter = 0;
  frame_speed = 4;

}

void MainMenuCharacter::render() {
  frame_counter++;
  if (frame_counter >= (60 / frame_speed)) {
    frame_counter = 0;
    current_frame++;

    if (current_frame > 3) current_frame = 0;

    frames.x = (float)current_frame * ((float)texture.width / 4);
  }

  DrawTextureRec(texture, frames, position, WHITE);
}

void MainMenuCharacter::unload_texture() {
  UnloadTexture(texture);
}



void main_menu() {
  WelcomeText welcome_text(400, 100, true);
  MainMenuCharacter main_character(((GetScreenWidth() / 2) - 16), ((GetScreenHeight() / 2) - 21), true);
  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(RAYWHITE);
      welcome_text.render();
      main_character.render();
    EndDrawing();
  }
  main_character.unload_texture();
}
