#include <iostream>
#include <string>
#include <raylib.h>
#include <physac.h>
#include "object.h"

// create a class for the main character in the main menu
class MainCharacter : public GameObject {
public:
  // declare the needed variables to store the
  // needed information for the character animation
  Image image_copy;
  Rectangle frames;
  int current_frame;
  int frame_counter;
  int frame_speed;
  std::string key;


  // declare the constructor
  MainCharacter(float pos_x, float pos_y, bool is_shown);

  // declare the render() method
  void render(std::string *level);

  // declare the unload_texture() method
  void unload_texture();
};
