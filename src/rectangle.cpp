#include "rectangle.hpp"

#include <sstream>

namespace green_leaf {
  Rectangle::Rectangle(int x, int y, int width, int height)
    : x_(x)
    , y_(y)
    , width_(width)
    , height_(height)
  {
  }

  Rectangle::Rectangle(int x, int y, Vector2 size)
    : Rectangle(x, y, size.x(), size.y())
  {
  }

  Rectangle::Rectangle(Vector2 coord, int width, int height)
    : Rectangle(coord.x(), coord.y(), width, height)
  {
  }

  Rectangle::Rectangle(Vector2 coord, Vector2 size)
    : Rectangle(coord.x(), coord.y(), size.x(), size.y())
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

  const SDL_Rect Rectangle::toSDLRect() const {
    SDL_Rect rect;

    rect.x = x_;
    rect.y = y_;
    rect.w = width_;
    rect.h = height_;

    return rect;
  }

  std::string Rectangle::toString() const {
    std::stringstream s;
    s << "Rectangle(" << x_ << ", " << y_ << ", " << width_ << ", " << height_ << ")";
    return s.str();
  }

  ::std::ostream& operator<<(::std::ostream& os, const Rectangle& r) {
    return os << r.toString();
  }
}
