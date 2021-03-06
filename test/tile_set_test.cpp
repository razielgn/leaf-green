#include "gtest/gtest.h"

#include "vector2.hpp"
#include "texture_mock.hpp"
#include "tile_set.hpp"

namespace green_leaf {
  class TileSetTest : public ::testing::Test {
  protected:
    TileSetTest() { }

    std::unique_ptr<Texture> texture_ = std::make_unique<TextureMock>(Vector2(48, 48));
    const Vector2 tile_size_ = Vector2(16, 16);
    const TileSet tile_set_ = TileSet(std::move(texture_), tile_size_, 1);
  };

  TEST_F(TileSetTest, TileSize) {
    EXPECT_EQ(tile_size_, tile_set_.tileSize());
  }

  TEST_F(TileSetTest, StartCode) {
    EXPECT_EQ(1u, tile_set_.startCode());
  }

  TEST_F(TileSetTest, RectangleFromCode) {
    EXPECT_EQ(Rectangle(0, 0, tile_size_), tile_set_.rectangleFromCode(1));
    EXPECT_EQ(Rectangle(1, 0, tile_size_), tile_set_.rectangleFromCode(2));
    EXPECT_EQ(Rectangle(2, 0, tile_size_), tile_set_.rectangleFromCode(3));
    EXPECT_EQ(Rectangle(0, 1, tile_size_), tile_set_.rectangleFromCode(4));
    EXPECT_EQ(Rectangle(1, 1, tile_size_), tile_set_.rectangleFromCode(5));
    EXPECT_EQ(Rectangle(2, 1, tile_size_), tile_set_.rectangleFromCode(6));
    EXPECT_EQ(Rectangle(0, 2, tile_size_), tile_set_.rectangleFromCode(7));
    EXPECT_EQ(Rectangle(1, 2, tile_size_), tile_set_.rectangleFromCode(8));
    EXPECT_EQ(Rectangle(2, 2, tile_size_), tile_set_.rectangleFromCode(9));
  }
}
