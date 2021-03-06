#pragma once

#include "rectangle.hpp"

namespace green_leaf {
  class Door {
  public:
    Door(const Rectangle rectangle, const std::string map)
      : rectangle_(rectangle)
      , map_(map)
    {
    }

    const Rectangle rectangle() const {
      return rectangle_;
    }

    const std::string map() const {
      return map_;
    }

  private:
    const Rectangle rectangle_;
    const std::string map_;
  };
}
