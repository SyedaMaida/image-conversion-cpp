#include "writer.h"
#include <fstream>

void writePPM_P6(const char* filename, const FrameBuffer& frame)
{
    std::ofstream file(filename, std::ios::binary);

    if (!file) return;

    // P6 header
    file << "P6\n";
    file << frame.width << " " << frame.height << "\n";
    file << "255\n";

    // Write pixel data (binary)
    for (int i = 0; i < frame.width * frame.height; i++) {
        file.write((char*)&frame.data[i].r, 1);
        file.write((char*)&frame.data[i].g, 1);
        file.write((char*)&frame.data[i].b, 1);
    }

    file.close();
}
