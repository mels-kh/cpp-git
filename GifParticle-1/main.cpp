
#include "gif.hpp"

const int width = 128;
const int height = 128;

gif::Pixel get_random_color() {
  return gif::Pixel{
      static_cast<uint8_t>(rand() % 128 + 128),
      static_cast<uint8_t>(rand() % 128 + 128),
      static_cast<uint8_t>(rand() % 128 + 128),
  };
}

int main() {
  const std::string filename{"./output.gif"};

  gif::GifWriter writer{filename, width, height, 2};

  srand(42);
  gif::Pixel color = get_random_color();

  int i = height / 2, j = width / 2;
  int i_speed = 1;
  int j_speed = 2;
  
  for (int frame_number = 0; frame_number < 1000; ++frame_number) {

    // write current position if gif
    gif::Frame frame{width, height};
    frame[{i, j}] = color;
    writer.write_frame(frame);

    // update position and speed
    i += i_speed;
    j += j_speed;
  

    if (i > height - 1) {
      i = height - 1;
      i_speed = -i_speed ;
    }
    if(j > width - 1)
    {
      j = width - 1;
      j_speed = -j_speed;
    }
    if(i < 0)
    {
      i = 0;
      i_speed = -i_speed;
    }
    if(j < 0)
    {
      j = 0;
      j_speed = -j_speed;
    }
    
    
    
  }
  return 0;
}
