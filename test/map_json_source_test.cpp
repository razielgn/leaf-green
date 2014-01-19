#include "gmock/gmock.h"
#include "map_json_source.hpp"
#include "tile_layer.hpp"
#include "tile_set.hpp"
#include "content_mock.hpp"

namespace green_leaf {
  using namespace ::testing;

  class MapJsonSourceTest : public TestWithParam<const MapJsonSource*> {
  protected:
    MapJsonSourceTest() { }
  };

  TEST_P(MapJsonSourceTest, Resolution) {
    EXPECT_EQ(Vector2(64, 60), GetParam()->resolution());
  }

  TEST_P(MapJsonSourceTest, TileSize) {
    EXPECT_EQ(Vector2(16, 20), GetParam()->tile_size());
  }

  TEST_P(MapJsonSourceTest, BackgroundLayer) {
    const TileLayer* backgroundLayer = GetParam()->backgroundLayer();

    EXPECT_EQ(Vector2(4, 3), backgroundLayer->size());

    std::vector<unsigned int> tiles = { 1, 2, 3, 4 };
    EXPECT_EQ(tiles, backgroundLayer->tiles());

    const TileSet* tile_set = backgroundLayer->tile_set();
    EXPECT_EQ(GetParam()->tile_size(), tile_set->tile_size());
    EXPECT_EQ(1, tile_set->start_code());
  }

  TEST_P(MapJsonSourceTest, FloorLayer) {
    const TileLayer* floorLayer = GetParam()->floorLayer();

    EXPECT_EQ(Vector2(4, 3), floorLayer->size());

    std::vector<unsigned int> tiles = { 5, 6, 7, 8 };
    EXPECT_EQ(tiles, floorLayer->tiles());

    const TileSet* tile_set = floorLayer->tile_set();
    EXPECT_EQ(GetParam()->tile_size(), tile_set->tile_size());
    EXPECT_EQ(5, tile_set->start_code());
  }

  TEST_P(MapJsonSourceTest, DecorationsLayer) {
    const TileLayer* decorationsLayer = GetParam()->decorationsLayer();

    EXPECT_EQ(Vector2(4, 3), decorationsLayer->size());

    std::vector<unsigned int> tiles = { 9, 10, 11, 12 };
    EXPECT_EQ(tiles, decorationsLayer->tiles());

    const TileSet* tile_set = decorationsLayer->tile_set();
    EXPECT_EQ(GetParam()->tile_size(), tile_set->tile_size());
    EXPECT_EQ(5, tile_set->start_code());
  }

  TEST_P(MapJsonSourceTest, ForegroundLayer) {
    const TileLayer* foregroundLayer = GetParam()->foregroundLayer();

    EXPECT_EQ(Vector2(4, 3), foregroundLayer->size());

    std::vector<unsigned int> tiles = { 13, 14, 15, 16 };
    EXPECT_EQ(tiles, foregroundLayer->tiles());

    const TileSet* tile_set = foregroundLayer->tile_set();
    EXPECT_EQ(GetParam()->tile_size(), tile_set->tile_size());
    EXPECT_EQ(5, tile_set->start_code());
  }

  const ContentMock content_;
  const MapJsonSource map_source_1 =
    MapJsonSource(&content_, std::string("test_map.json"));
  const MapJsonSource map_source_2 =
    MapJsonSource(&content_, std::string("test_map_shuffled.json"));

  INSTANTIATE_TEST_CASE_P(
    MapJsonSourceTest1,
    MapJsonSourceTest,
    ::testing::Values(&map_source_1)
  );

  INSTANTIATE_TEST_CASE_P(
    MapJsonSourceTest2,
    MapJsonSourceTest,
    ::testing::Values(&map_source_2)
  );
}
