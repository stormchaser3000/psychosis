#include <iosteam>
#include "main_menu.h"



// define WelcomeText member functions
WelcomeText::WelcomeText(int pos_x, int pos_y, bool is_shown) {
  position.x = pos_x;
  position.y = pos_y;
  visible = is_shown;
  font = LoadFont("assets/DejavuSans-Bold.ttf");
}

WelcomeText::render() {
  DrawTextEx(font, "Psychosis", position, 24, 1, PURPLE);
}



// define MainMenuCharacter member functions
MainMenuCharacter::MainMenuCharacter(int pos_x, int pos_y, bool is_shown) {
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

MainMenuCharacter::render() {
  frames_counter++
  if (frame_counter >= (60 / frame_speed)) {
    frame_counter = 0
    current_frame++

    if ()

  }
}



void main_menu() {
  WelcomeText welcome_text(400, 500, true);
  MainMenuCharacter main_character((ScreenWidth()-32), (ScreenHeight()-42), true);
  while (!WindowShouldClose()) {
    BeginDrawing()
      ClearBackground(RAYWHITE);

  }
}
