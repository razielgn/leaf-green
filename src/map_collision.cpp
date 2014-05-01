#include "map_collision.hpp"

#include "collisions_layer.hpp"
#include "movement.hpp"
#include "player_movement.hpp"

#include "iostream"

namespace green_leaf {
  MapCollision::MapCollision(const CollisionsLayer& collisions_layer)
    : collisions_layer_(collisions_layer)
  {
  }

  void MapCollision::update(PlayerMovement& player_movement, const Vector2 position, const Vector2 destination) const {
    if(!collisions_layer_.canMove(position, destination)) {
      player_movement.clashing(true);
    }
  }
}
