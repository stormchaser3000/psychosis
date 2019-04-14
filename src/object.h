#include <raylib.h>
#include <physac.h>

#ifndef _OBJECT_H_
#define _OBJECT_H_
class GameObject {
public:
  Vector2 position;
  Image image;
  Texture2D texture;
  bool visible;
};
#endif
