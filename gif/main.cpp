#include "gif.hpp"

#include <cmath>
#include <random>
#include <string>

const int width = 128;
const int height = 128;

int main(int argc, const char *argv[]) {
  const std::string filename{"./output.gif"};

  gif::GifWriter writer{filename, width, height, 10};

  for (int frame_number = 0; frame_number < 127; ++frame_number) {
    
    gif::Pixel pix{255,255,255};
    gif::Frame frame{width, height, pix};
    
    for (std::size_t i = 0; i < height; ++i) {
      for (std::size_t j = 0; j < height; ++j) {
        frame[{frame_number, j}] = gif::Pixel{
            static_cast<uint8_t>(0000),
            static_cast<uint8_t>(0000),
            static_cast<uint8_t>(0000),
        };
      }
    }
    
    writer.write_frame(frame);
  }

  return 0;
}