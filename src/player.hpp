#pragma once
#ifndef GL_PLAYER_HPP
#define GL_PLAYER_HPP

#include "player_animation.hpp"

namespace green_leaf {
  class Content;
  class Graphics;
  enum class Direction;
  class PlayerMovement;

  class Player {
  public:
    Player(const Direction direction);

    void loadContent(const Content& graphics);

    void update(const PlayerMovement& player_movement);
    void draw(const Graphics& graphics) const;

  private:
    PlayerAnimation animation_;
  };
}

#endif
