#include "sdl_content.hpp"

#include "bitmap_font.hpp"
#include "sdl_texture.hpp"
#include "map_json_source.hpp"

namespace green_leaf {
  SDLContent::SDLContent(const Graphics& graphics, const std::string base_path)
    : graphics_(graphics)
    , base_path_(base_path)
  {
  }

  std::string SDLContent::fullPath(const std::string path) const {
    return base_path_ + dir_sep_ + path;
  }

  std::unique_ptr<const Texture> SDLContent::loadTexture(const std::string path) const {
    return std::unique_ptr<const Texture>(
      SDLTexture::fromPath(graphics_, fullPath(path))
    );
  }

  std::unique_ptr<const MapSource> SDLContent::loadMap(const std::string path) const {
    std::string full_path = fullPath(path) + maps_ext_;

    return std::make_unique<const MapJsonSource>(*this, full_path);
  }

  std::unique_ptr<const BitmapFont> SDLContent::loadBitmapFont(const std::string path) const {
    return std::make_unique<const BitmapFont>(loadTexture(path));
  }
}
