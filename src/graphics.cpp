#include "graphics.hpp"
#include "texture.hpp"

namespace green_leaf {
  Graphics::Graphics() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
      throw "Could not initialize SDL system";
    }

    window_ = SDL_CreateWindow("Hello there!",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               640,
                               480,
                               SDL_WINDOW_SHOWN);

    if(!window_) {
      throw "Could not create SDL window";
    }

    renderer_ = SDL_CreateRenderer(window_,
                                   -1,
                                   SDL_RENDERER_ACCELERATED |
                                   SDL_RENDERER_PRESENTVSYNC);
  }

  Graphics::~Graphics() {
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    SDL_Quit();
  }

  void Graphics::clear() {
    SDL_RenderClear(renderer_);
  }

  void Graphics::drawTexture(Texture* texture, SDL_Rect* source, SDL_Rect* dest) {
    SDL_RenderCopy(renderer_, texture->data(), source, dest);
  }

  void Graphics::present() {
    SDL_RenderPresent(renderer_);
  }
}
