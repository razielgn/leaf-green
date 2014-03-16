#ifndef GL_MAP_OFFSET_HPP
#define GL_MAP_OFFSET_HPP

#include "vector2.hpp"

namespace green_leaf {
  class MapOffset {
  public:
    MapOffset(Vector2 tile_size, Vector2 screen_size);

    Vector2 centerOffset(Vector2 center) const;

  private:
    const Vector2 tile_size_;
    const Vector2 screen_size_;
  };
}

#endif