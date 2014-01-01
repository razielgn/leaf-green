#ifndef GL_RECTANGLE_HPP
#define GL_RECTANGLE_HPP

#include <SDL.h>
#include <iostream>
#include <string>

#include "vector2.hpp"

namespace green_leaf {
  class Rectangle {
  public:
    Rectangle(int x, int y, int width, int height);
    Rectangle(int x, int y, Vector2 size);
    Rectangle(Vector2 coord, int width, int height);
    Rectangle(Vector2 coord, Vector2 size);

    Rectangle scale(int factor) const;
    const SDL_Rect toSDLRect() const;

    std::string toString() const;

    int x() const {
      return x_;
    }

    int y() const {
      return y_;
    }

    int width() const {
      return width_;
    }

    int height() const {
      return height_;
    }

    bool operator==(const Rectangle& rect) const {
      return (this == &rect) || (
        x_ == rect.x_ &&
        y_ == rect.y_ &&
        width_ == rect.width_ &&
        height_ == rect.height_
      );
    }

    bool operator!=(const Rectangle& rect) const {
      return !(*this == rect);
    }

  private:
    const int x_;
    const int y_;
    const int width_;
    const int height_;
  };

  ::std::ostream& operator<<(::std::ostream& os, const Rectangle& r);
}

#endif
