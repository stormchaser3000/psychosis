#include <iostream>
#include <string>
#include "characters.h"

// define MainMenuCharacter member functions


// define the main character constructor for the main menu
MainCharacter::MainCharacter(float pos_x, float pos_y, bool is_shown) {
  // set the position of the character using the given params and the pixel size of the character
  position.x = pos_x - (16 * 2);
  position.y = pos_y - (21 * 2);

  // set if the character is visible based on the given params
  visible = is_shown;

  // load the texture to use for the main character and assign the returned
  // value of type Texture2D to texture
  image = LoadImage("assets/characters/Main Character.png");

  // define the rectangle which will be used to create the animation
  frames.x = 0.0f;
  frames.y = 0.0f;
  frames.width = (float)image.width/4;
  frames.height = (float)image.height/4;

  // set the current frame and frame counter to zero
  current_frame = 0;
  frame_counter = 0;

  // set the animation speed for the main character to 4 frames per second
  frame_speed = 6;

}


void MainCharacter::render(std::string *level, bool *game_starting) {
  if (*level == "main menu") {
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
      frames.x = (float)current_frame * ((float)image.width / 4);
    }
  }

  if (*game_starting == true) {
    frames.y = ((float)image.height / 4) * 0;
    frames.x = 0.0f * ((float)image.width / 4);
    *game_starting = false;
  }

  if (*level == "level1") {

    // change animation depending on what key is pressed when level is equal to
    // level 1
    if (IsKeyDown(KEY_S)) {
      key = "S";
      frame_counter++;

      if (frame_counter >= (60 / frame_speed)) {
        frame_counter = 0;
        current_frame++;

        if (current_frame > 3) current_frame = 0;

        frames.y = ((float)image.height / 4) * 0;
        frames.x = (float)current_frame * ((float)image.width / 4);
      }
    }


    else if (IsKeyDown(KEY_W)) {
      key = "W";
      frame_counter++;

      if (frame_counter >= (60 / frame_speed)) {
        frame_counter = 0;
        current_frame++;

        if (current_frame > 3) current_frame = 0;

        frames.y = ((float)image.height / 4) * 3;
        frames.x = (float)current_frame * ((float)image.width / 4);
      }
    }


    else if (IsKeyDown(KEY_A)) {
      key = "A";
      frame_counter++;

      if (frame_counter >= (60 / frame_speed)) {
        frame_counter = 0;
        current_frame++;

        if (current_frame > 3) current_frame = 0;

        frames.y = ((float)image.height / 4) * 1;
        frames.x = (float)current_frame * ((float)image.width / 4);
      }
    }


    else if (IsKeyDown(KEY_D)) {
      key = "D";
      frame_counter++;

      if (frame_counter >= (60 / frame_speed)) {
        frame_counter = 0;
        current_frame++;

        if (current_frame > 3) current_frame = 0;

        frames.y = ((float)image.height / 4) * 2;
        frames.x = (float)current_frame * ((float)image.width / 4);
      }
    }

    // if no key is pressed then set sprite texture to standing and have the
    // direction depend on what key was pressed last
    if (((!IsKeyDown(KEY_A)) && (!IsKeyDown(KEY_D))) && ((!IsKeyDown(KEY_W)) && (!IsKeyDown(KEY_S)))) {
      if (key == "W") {
        frames.y = ((float)image.height / 4) * 3;
        frames.x = 0.0f;
      }else if (key == "A") {
        frames.y = ((float)image.height / 4) * 1;
        frames.x = 0.0f;
      }else if (key == "S") {
        frames.y = ((float)image.height / 4) * 0;
        frames.x = 0.0f;
      }else if (key == "W") {
        frames.y = ((float)image.height / 4) * 2;
        frames.x = 0.0f;
      }
    }
  }

  image_copy = ImageCopy(image);
  ImageCrop(&image_copy, frames);
  ImageResizeNN(&image_copy, image_copy.width * 2, image_copy.height * 2);
  texture = LoadTextureFromImage(image_copy);
  DrawTexture(texture, position.x, position.y, WHITE);
}


void MainCharacter::unload_texture() {
  UnloadTexture(texture);
}
