#include "content.hpp"
#include "graphics.hpp"
#include "map.hpp"
#include "map_source.hpp"
#include "movement.hpp"
#include "player_movement.hpp"
#include "tile_layer.hpp"
#include "vector2.hpp"
#include "rectangle.hpp"

namespace green_leaf {
  Map::Map(const MapSource* map_source, Vector2 playerPosition)
    : map_source_(map_source)
    , playerPosition_(playerPosition)
    , destination_(playerPosition_)
    , screenOffset_(Vector2(0, 0))
  {
  }

  void Map::update(const PlayerMovement* player_movement, Vector2 screenSize) {
    if(player_movement->moving()) {
      switch(player_movement->movement()) {
        case Movement::Right:
          destination_ = playerPosition_ + Vector2(1, 0); break;
        case Movement::Left:
          destination_ = playerPosition_ - Vector2(1, 0); break;
        case Movement::Up:
          destination_ = playerPosition_ - Vector2(0, 1); break;
        case Movement::Down:
          destination_ = playerPosition_ + Vector2(0, 1); break;
        default: break;
      }
    }

    screenOffset_ = drawOffset(playerPosition_, screenSize);

    if(player_movement->moving()) {
      Vector2 destination = drawOffset(destination_, screenSize);
      screenOffset_ = screenOffset_ + (destination - screenOffset_) * player_movement->progress();

      if(player_movement->finished()) {
        playerPosition_ = destination_;
      }
    }
  }

  Vector2 Map::drawOffset(Vector2 center, Vector2 screenSize) const {
    const Vector2 tile_size = map_source_->tile_size();

    return (screenSize / 2 - tile_size / 2 + Vector2(0, 2)) -
      center * tile_size;
  }

  void Map::drawBackground(const Graphics* graphics) const {
    map_source_->backgroundLayer()->draw(graphics, screenOffset_);
    map_source_->floorLayer()->draw(graphics, screenOffset_);
    map_source_->decorationsLayer()->draw(graphics, screenOffset_);
  }

  void Map::drawForeground(const Graphics* graphics) const {
    map_source_->foregroundLayer()->draw(graphics, screenOffset_);
  }
}
