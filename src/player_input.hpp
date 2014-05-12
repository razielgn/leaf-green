#pragma once
#ifndef GL_PLAYER_INPUT_HPP
#define GL_PLAYER_INPUT_HPP

namespace green_leaf {
  class PlayerInput {
  public:
    virtual void update() = 0;

    virtual bool a() = 0;
    virtual bool aPressed() = 0;
    virtual bool b() = 0;
    virtual bool bPressed() = 0;
    virtual bool up() = 0;
    virtual bool upPressed() = 0;
    virtual bool down() = 0;
    virtual bool downPressed() = 0;
    virtual bool left() = 0;
    virtual bool right() = 0;
    virtual bool start() = 0;
    virtual bool startPressed() = 0;
    virtual bool select() = 0;
    virtual bool r() = 0;
    virtual bool l() = 0;
    virtual bool escape() = 0;
  };
}

#endif
