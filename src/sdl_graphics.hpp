#ifndef GL_SDL_GRAPHICS_HPP
#define GL_SDL_GRAPHICS_HPP

#include <SDL.h>
#include "graphics.hpp"
#include "vector2.hpp"

namespace green_leaf {
  class Rectangle;
  class Texture;

  class SDLGraphics : public Graphics {
  public:
    SDLGraphics(bool visible = true);
    ~SDLGraphics();

    void clear() const;
    void drawTexture(const Texture* texture, const Rectangle destination, const Rectangle source) const;
    void drawTexture(const Texture* texture, const Rectangle destination) const;
    void present() const;

    SDL_Renderer* renderer() const {
      return renderer_;
    }

    Vector2 size() const {
      return size_;
    }

  private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;

    const Vector2 size_ = Vector2(240, 160);
    int scale_ = 4;
  };
}

#endif
