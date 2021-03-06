#pragma once

#include "collisions_layer.hpp"
#include "map_source.hpp"
#include "tile_layer.hpp"
#include "tile_set.hpp"

namespace green_leaf {
  class Content;

  class MapJsonSource : public MapSource {
  public:
    MapJsonSource(const Content& content, const std::string path);

    Vector2 resolution() const override {
      return resolution_;
    }

    Vector2 tileSize() const override {
      return tile_size_;
    }

    const TileLayer& backgroundLayer() const override {
      return *background_tile_layer_;
    }

    const TileLayer& decorationsLayer() const override {
      return *decorations_tile_layer_;
    }

    const TileLayer& floorLayer() const override {
      return *floor_tile_layer_;
    }

    const TileLayer& foregroundLayer() const override {
      return *foreground_tile_layer_;
    }

    const CollisionsLayer& collisionsLayer() const override {
      return *collisions_layer_;
    }

    const std::vector<Object>& objects() const override {
      return objects_;
    }

    const std::vector<Door>& doors() const override {
      return doors_;
    }

  private:
    Vector2 resolution_;
    Vector2 tile_size_;

    std::unique_ptr<const TileSet> background_tile_set_;
    std::unique_ptr<const TileSet> decorations_tile_set_;

    std::unique_ptr<const TileLayer> background_tile_layer_;
    std::unique_ptr<const TileLayer> floor_tile_layer_;
    std::unique_ptr<const TileLayer> decorations_tile_layer_;
    std::unique_ptr<const TileLayer> foreground_tile_layer_;
    std::unique_ptr<const CollisionsLayer> collisions_layer_;

    std::vector<Object> objects_;
    std::vector<Door> doors_;
  };
}
