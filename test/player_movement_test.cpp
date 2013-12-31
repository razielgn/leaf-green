#include "gmock/gmock.h"
#include "player_movement.hpp"
#include "game_time.hpp"

#include "input_mock.hpp"

namespace green_leaf {
  using ::testing::FloatEq;
  using ::testing::Ne;
  using ::testing::Return;
  using ::testing::_;

  class PlayerMovementTest : public ::testing::Test {
  protected:
    PlayerMovementTest()
      : game_time_(GameTime(10, 0))
    {
    }

    virtual void SetUp() {
      player_movement_ = new PlayerMovement();
    }

    virtual void TearDown() {
      delete player_movement_;
    }

    void onlyPressed(InputKey key) {
      EXPECT_CALL(input_, isKeyDown(key)).WillRepeatedly(Return(true));
      EXPECT_CALL(input_, isKeyDown(Ne(key))).WillRepeatedly(Return(false));
    }

    void nothingPressed() {
      EXPECT_CALL(input_, isKeyDown(_)).WillRepeatedly(Return(false));
    }

    PlayerMovement* player_movement_;
    InputMock input_;
    GameTime game_time_;
  };

  TEST_F(PlayerMovementTest, DownKeyPressed) {
    onlyPressed(InputKey::Down);

    player_movement_->update(&input_, &game_time_);

    EXPECT_TRUE(player_movement_->moving());
    EXPECT_EQ(Movement::Down, player_movement_->movement());
  }

  TEST_F(PlayerMovementTest, RightKeyPressed) {
    onlyPressed(InputKey::Right);

    player_movement_->update(&input_, &game_time_);

    EXPECT_TRUE(player_movement_->moving());
    EXPECT_EQ(Movement::Right, player_movement_->movement());
  }

  TEST_F(PlayerMovementTest, LeftKeyPressed) {
    onlyPressed(InputKey::Left);

    player_movement_->update(&input_, &game_time_);

    EXPECT_TRUE(player_movement_->moving());
    EXPECT_EQ(Movement::Left, player_movement_->movement());
  }

  TEST_F(PlayerMovementTest, UpKeyPressed) {
    onlyPressed(InputKey::Up);

    player_movement_->update(&input_, &game_time_);

    EXPECT_TRUE(player_movement_->moving());
    EXPECT_EQ(Movement::Up, player_movement_->movement());
  }

  TEST_F(PlayerMovementTest, NothingPressed) {
    nothingPressed();

    player_movement_->update(&input_, &game_time_);

    EXPECT_FALSE(player_movement_->moving());
    EXPECT_EQ(Movement::Still, player_movement_->movement());
  }

  TEST_F(PlayerMovementTest, InputSkippedWhenMoving) {
    onlyPressed(InputKey::Up);

    player_movement_->update(&input_, &game_time_);

    EXPECT_TRUE(player_movement_->moving());
    EXPECT_EQ(Movement::Up, player_movement_->movement());

    onlyPressed(InputKey::Down);

    player_movement_->update(&input_, &game_time_);

    EXPECT_TRUE(player_movement_->moving());
    EXPECT_EQ(Movement::Up, player_movement_->movement());
  }

  TEST_F(PlayerMovementTest, ProgressFrozenWhenStill) {
    nothingPressed();

    player_movement_->update(&input_, &game_time_);

    EXPECT_THAT(player_movement_->progress(), FloatEq(0.0));
  }

  TEST_F(PlayerMovementTest, AnimationProgress) {
    onlyPressed(InputKey::Down);

    int elapsed = 0;
    float progress = 0.0;

    do {
      GameTime game_time(elapsed, 0);
      player_movement_->update(&input_, &game_time);

      EXPECT_THAT(player_movement_->progress(), FloatEq(progress));

      progress += 0.2;
      elapsed = 50;
    } while(progress <= 1.0);
  }

  TEST_F(PlayerMovementTest, Finished) {
    onlyPressed(InputKey::Down);

    GameTime game_time(125, 0);

    player_movement_->update(&input_, &game_time);
    EXPECT_FALSE(player_movement_->finished());

    player_movement_->update(&input_, &game_time);
    EXPECT_TRUE(player_movement_->finished());
  }

  TEST_F(PlayerMovementTest, ResetStateAfterFinished) {
    onlyPressed(InputKey::Down);

    GameTime game_time(250, 0);

    player_movement_->update(&input_, &game_time);
    EXPECT_TRUE(player_movement_->finished());
    EXPECT_TRUE(player_movement_->moving());
    EXPECT_THAT(player_movement_->progress(), FloatEq(1.0));

    nothingPressed();

    player_movement_->update(&input_, &game_time_);
    EXPECT_FALSE(player_movement_->finished());
    EXPECT_FALSE(player_movement_->moving());
    EXPECT_THAT(player_movement_->progress(), FloatEq(0.0));
  }
}
