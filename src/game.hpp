#ifndef GL_GAME_CPP
#define GL_GAME_CPP

#include "content.hpp"
#include "graphics.hpp"
#include "keyboard_input.hpp"
#include "screen_manager.hpp"

#include <memory>

namespace green_leaf {
  class Graphics;
  class KeyboardInput;
  class Content;

  class Game {
  public:
    Game();

    void loadContent();
    void run();
    void update();
    void draw() const;
    void stop();

  private:
    std::unique_ptr<Graphics> graphics_;
    std::unique_ptr<KeyboardInput> input_;
    std::unique_ptr<Content> content_;
    ScreenManager screen_manager_;

    unsigned int total_time_;
    bool running_;
  };
}

#endif
