#include <raylib.h>
#include <physac.h>

#ifndef _DUNGEONS_H_
#define _DUNGEONS_H_

struct Array2D {
  int width;
  int height;
};

class Level1 {
  Array2D section_one;
  Vector2 position;
  Image floor;

  Level1();
  void render();
};
#endif
