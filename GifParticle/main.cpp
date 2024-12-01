
#include "gif.hpp"

const int width = 256;
const int height = 256;

int main() {
	const std::string filename{"./output.gif"};
	int k = 10;
	gif::GifWriter writer{filename, width, height, k};

	int i = 0, j = width;
	int i_speed = 1;

	for (int frame_number = 1; frame_number < 25 ; ++frame_number) {
		gif::Frame frame{width, height};

		frame[{i, j}] = gif::Pixel{255,255,255};
		writer.write_frame(frame);
    k ++;
    ++i_speed;
		i += i_speed;
    j+= 2;
    
		
		// если i > height - 1, то i = height - 1
		i = std::min(i, height - 1);
    if(i > height - 1)
    {
      i = height - 1;
    }
	}
	return 0;
}
