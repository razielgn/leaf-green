#pragma once

#include "map.hpp"
#include "map_collision.hpp"
#include "map_source.hpp"
#include "movement_timing.hpp"
#include "player.hpp"
#include "player_movement.hpp"
#include "screen.hpp"
#include "vector2.hpp"

#include <memory>

namespace green_leaf {
  class Content;
  class Graphics;
  class PlayerInput;

  class MapScreen : public Screen {
  public:
    MapScreen(ScreenManager& screen_manager, const std::string map_name, Vector2 start_pos, Direction direction, const Vector2 screen_size);

    void loadContent(const Content& content) override;
    void update(PlayerInput& input, const GameTime game_time) override;
    void draw(const Graphics& graphics) const override;

  private:
    const std::string map_name_;
    const Vector2 screen_size_;

    std::unique_ptr<const MapSource> map_source_;
    std::unique_ptr<Map> map_;
    std::unique_ptr<Screen> maybe_next_screen_;
    std::unique_ptr<const MapCollision> map_collision_;

    Player player_;
    PlayerMovement player_movement_;
    MovementTiming player_timing_;
    Vector2 player_position_;
    bool clashing_;

    void updateInteractions(PlayerInput& input);
    void updateIdlePlayer(PlayerInput& input);
    void updateTurningPlayer(const GameTime game_time);
    void updateMovingPlayer(PlayerInput& input, const GameTime game_time);
  };
}
