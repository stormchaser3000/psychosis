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
void WelcomeText::render() {
  DrawTexture(texture, position.x, position.y, WHITE);
}

// create a function that unloads the character texture
void WelcomeText::unload_texture() {
  UnloadTexture(texture);
}



// define MainMenuCharacter member functions

// define the main character constructor for the main menu
MainMenuCharacter::MainMenuCharacter(float pos_x, float pos_y, bool is_shown) {
  // set the position of the character using the given params
  position.x = pos_x - 16;
  position.y = pos_y - 21;

  // set if the character is visible based on the given params
  visible = is_shown;

  // load the texture to use for the main character and assign the returned
  // value of type Texture2D to texture
  texture = LoadTexture("assets/characters/Main Character.png");

  // define the rectangle which will be used to create the animation
  frames.x = 0.0f;
  frames.y = 0.0f;
  frames.width = (float)texture.width/4;
  frames.height = (float)texture.height/4;

  // set the current frame and frame counter to zero
  current_frame = 0;
  frame_counter = 0;

  // set the animation speed for the main character to 4 frames per second
  frame_speed = 4;

}

void MainMenuCharacter::render() {
  // increment the frame counter by one every time this method is called
  frame_counter++;

  // if the frame counter is greater than the frame rate divided by the frame
  // speed, then set the frame counter to zero and increment current frame by
  // one
  if (frame_counter >= (60 / frame_speed)) {
    frame_counter = 0;
    current_frame++;

    // if current_frame is greater than 3 set it to 0. the reason for this is
    // that this variable counts the frame of the animation that the main character
    // is in. the main character animation only has 4 frames and the frame counting
    // starts at 0 so if the current frame is greater than 3 then current_frame
    // should be set to 0.
    if (current_frame > 3) current_frame = 0;

    // set the x position of the rectangle (which determines which part of the
    // animation is being rendered). this is determined by multiplying the current
    // frame by the width of the texture divided by 4 (the number of animation frames)
    frames.x = (float)current_frame * ((float)texture.width / 4);
  }

  DrawTextureRec(texture, frames, position, WHITE);
}

void MainMenuCharacter::unload_texture() {
  UnloadTexture(texture);
}



void main_menu() {
  // create the main menu title by creating an instance of the WelcomeText class
  WelcomeText welcome_text(400, 100, true);

  // create the main character in the main menu by creating an instance of the
  // MainMenuCharacter class. put the main character in the middle of the screen
  MainMenuCharacter main_character((GetScreenWidth() / 2), (GetScreenHeight() / 2), true);

  // start the main loop
  while (!WindowShouldClose()) {

    // render all the things
    BeginDrawing();
      ClearBackground(RAYWHITE);
      welcome_text.render();
      main_character.render();
    EndDrawing();
  }

  // unload the textures
  welcome_text.unload_texture();
  main_character.unload_texture();
}
