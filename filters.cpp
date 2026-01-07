#include "filters.h"

FrameBuffer smoothFilter(const FrameBuffer& input)
{
    FrameBuffer output;
    output.width = input.width;
    output.height = input.height;
    output.data = new Pixel[input.width * input.height];

    for (int y = 0; y < input.height; y++) {
        for (int x = 0; x < input.width; x++) {

            int sum = 0;
            int count = 0;

            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {

                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < input.width &&
                        ny >= 0 && ny < input.height) {

                        int idx = ny * input.width + nx;
                        sum += input.data[idx].r;
                        count++;
                    }
                }
            }

            int idx = y * input.width + x;
            uint8_t avg = sum / count;

            output.data[idx].r = avg;
            output.data[idx].g = avg;
            output.data[idx].b = avg;
        }
    }

    return output;
}
