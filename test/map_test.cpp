#include "gmock/gmock.h"
#include "map_source_mock.hpp"
#include "map.hpp"

namespace green_leaf {
  using namespace ::testing;

  class MapTest : public Test {
  protected:
    MapTest() { }

    MapSourceMock map_source_;
    Map map_ = Map(&map_source_, Vector2(0, 0));
  };

  TEST_F(MapTest, DrawOffset) {
    EXPECT_CALL(map_source_, tile_size()).WillRepeatedly(Return(Vector2(16, 16)));

    const Vector2 screenSize = Vector2(240, 160);

    EXPECT_EQ(Vector2(112, 74), map_.drawOffset(Vector2(0, 0), screenSize));
    EXPECT_EQ(Vector2(16, -22), map_.drawOffset(Vector2(6, 6), screenSize));
    EXPECT_EQ(Vector2(0, 10),   map_.drawOffset(Vector2(7, 4), screenSize));
    EXPECT_EQ(Vector2(0, -6),   map_.drawOffset(Vector2(7, 5), screenSize));
    EXPECT_EQ(Vector2(0, -22),  map_.drawOffset(Vector2(7, 6), screenSize));
  }
}
