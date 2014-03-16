#ifndef GL_MESSAGE_BOX_STATE_HPP
#define GL_MESSAGE_BOX_STATE_HPP

#include "game_time.hpp"

namespace green_leaf {
  class Input;

  struct MessageBoxState {
    MessageBoxState();

    unsigned int character() const {
      return character_;
    }

    unsigned int line() const {
      return line_;
    }

    unsigned int message() const {
      return message_;
    }

    void nextLine();
    void nextMessage();

    void update(Input& input, GameTime game_time);

  private:
    unsigned int character_;
    unsigned int line_;
    unsigned int message_;
    unsigned int elapsed_;
  };
}

#endif