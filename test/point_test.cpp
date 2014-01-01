#include "gtest/gtest.h"
#include <string>
#include "point.hpp"

namespace green_leaf {
  class PointTest : public ::testing::Test {
  protected:
    PointTest() :
      point_(Point(1, 2))
    {
    }

    const Point point_;
  };

  TEST_F(PointTest, DefaultConstructor) {
    EXPECT_EQ(1, point_.x());
    EXPECT_EQ(2, point_.y());
  }

  TEST_F(PointTest, Identity) {
    EXPECT_EQ(point_, point_);
  }

  TEST_F(PointTest, Equality) {
    EXPECT_EQ(Point(1, 2), point_);
  }

  TEST_F(PointTest, Inequality) {
    EXPECT_NE(Point(1, 1), point_);
  }

  TEST_F(PointTest, Assignment) {
    Point point(1, 2);
    point = Point(3, 4);

    EXPECT_EQ(3, point.x());
    EXPECT_EQ(4, point.y());
  }

  TEST_F(PointTest, ToString) {
    ASSERT_EQ(std::string("Point(1, 2)"), point_.toString());
  }

  TEST_F(PointTest, Sum) {
    EXPECT_EQ(Point(2, 5), Point(0, 0) + Point(2, 5));
    EXPECT_EQ(Point(2, 5), Point(1, 2) + Point(1, 3));
  }

  TEST_F(PointTest, Difference) {
    EXPECT_EQ(Point(-2, -5), Point(0, 0) - Point(2, 5));
    EXPECT_EQ(Point(-0, -1), Point(1, 2) - Point(1, 3));
  }

  TEST_F(PointTest, Multiplication) {
    EXPECT_EQ(Point(0, 0), Point(0, 0) * 0.0f);
    EXPECT_EQ(Point(0, 0), Point(1, 4) * 0.0f);
    EXPECT_EQ(Point(4, -8), Point(2, -4) * 2.0f);
  }

  TEST_F(PointTest, MultiplicationByPoint) {
    EXPECT_EQ(Point(0, 0), Point(0, 0) * Point(1, 2));
    EXPECT_EQ(Point(3, 20), Point(1, 4) * Point(3, 5));
  }

  TEST_F(PointTest, DivisionByPoint) {
    EXPECT_EQ(Point(0, 0), Point(0, 0) / Point(1, 1));
    EXPECT_EQ(Point(2, 2), Point(20, 10) / Point(10, 5));
  }
}
