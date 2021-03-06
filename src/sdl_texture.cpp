#include "sdl_texture.hpp"

#include "sdl_graphics.hpp"

#include <SDL_image.h>

namespace green_leaf {
  Vector2 fetchTextureSize(SDL_Texture* texture) {
    int width = 0, height = 0;
    int return_value = SDL_QueryTexture(texture, NULL, NULL, &width, &height);

    if(return_value != 0) {
      throw "Could not extract width and height from texture.";
    }

    return Vector2(width, height);
  }

  std::unique_ptr<const SDLTexture> SDLTexture::fromPath(const Graphics& graphics_, std::string relative_path) {
    const SDLGraphics& graphics = static_cast<const SDLGraphics&>(graphics_);

    SDL_Surface* surface = IMG_Load(relative_path.c_str());
    if (!surface) { throw "Could not load image"; }

    SDL_Texture* sdl_texture = SDL_CreateTextureFromSurface(&graphics.renderer(), surface);
    SDL_FreeSurface(surface);
    if (!sdl_texture) { throw "Could create texture from file"; }

    Vector2 textureSize = fetchTextureSize(sdl_texture);

    auto texture = std::unique_ptr<SDLTexture>(new SDLTexture(textureSize));
    texture->loadData(sdl_texture);

    return std::move(texture);
  }

  SDLTexture::SDLTexture(Vector2 size)
    : data_(nullptr)
    , size_(size)
  {
  }

  void SDLTexture::loadData(SDL_Texture* data) {
    data_ = data;
  }

  SDLTexture::~SDLTexture() {
    if(data_ != nullptr) {
      SDL_DestroyTexture(data_);
    }
  }
}
