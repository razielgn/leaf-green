#ifndef GL_MAP_SCREEN_HPP
#define GL_MAP_SCREEN_HPP

#include "map.hpp"
#include "map_source.hpp"
#include "player.hpp"
#include "player_movement.hpp"
#include "screen.hpp"
#include "vector2.hpp"

#include <memory>

namespace green_leaf {
  class Content;
  class Graphics;
  class Input;

  class MapScreen : public Screen {
  public:
    MapScreen(std::string map_name, Vector2 start_pos, Vector2 screen_size);

    void loadContent(const Content& content);
    void update(Input& input, const GameTime game_time);
    void draw(const Graphics& graphics) const;

  private:
    const std::string map_name_;
    const Vector2 start_pos_;
    const Vector2 screen_size_;

    std::unique_ptr<const MapSource> map_source_;
    std::unique_ptr<Map> map_;
    Player player_;
    PlayerMovement player_movement_;
  };
}

#endif
