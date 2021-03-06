#pragma once

#include "content.hpp"
#include "screen.hpp"

#include "gmock/gmock.h"

namespace green_leaf {
  class ScreenMock : public Screen {
  public:
    ScreenMock(ScreenManager& screen_manager)
      : Screen(screen_manager) { }
    ~ScreenMock() { }

    MOCK_METHOD1(loadContent, void(const Content& content));
    MOCK_METHOD2(update, void(PlayerInput& input, const GameTime game_time));
    MOCK_CONST_METHOD1(draw, void(const Graphics& graphics));
  };
}
