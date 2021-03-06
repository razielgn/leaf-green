#pragma once

#include "door.hpp"
#include "object.hpp"
#include "vector2.hpp"

namespace green_leaf {
  class CollisionsLayer;
  class TileLayer;

  class MapSource {
  public:
    virtual ~MapSource() { }

    virtual const TileLayer& backgroundLayer() const = 0;
    virtual const TileLayer& decorationsLayer() const = 0;
    virtual const TileLayer& floorLayer() const = 0;
    virtual const TileLayer& foregroundLayer() const = 0;
    virtual const CollisionsLayer& collisionsLayer() const = 0;
    virtual const std::vector<Object>& objects() const = 0;
    virtual const std::vector<Door>& doors() const = 0;

    virtual Vector2 resolution() const = 0;
    virtual Vector2 tileSize() const = 0;
  };
}
