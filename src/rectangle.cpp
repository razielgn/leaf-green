#include "rectangle.hpp"

namespace green_leaf {
  Rectangle::Rectangle(int x, int y, int width, int height)
    : x_(x)
    , y_(y)
    , width_(width)
    , height_(height)
  {
  }

  Rectangle Rectangle::scale(int factor) const {
    return Rectangle(
      factor * x_,
      factor * y_,
      factor * width_,
      factor * height_
    );
  }

  SDL_Rect Rectangle::toSDLRect() const {
    SDL_Rect rect;

    rect.x = x_;
    rect.y = y_;
    rect.w = width_;
    rect.h = height_;

    return rect;
  }
}