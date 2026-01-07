#include "edge.h"
#include <cstdlib>   // for abs()

FrameBuffer edge(const FrameBuffer& input)
{
    FrameBuffer output;
    output.width = input.width;
    output.height = input.height;
    output.data = new Pixel[input.width * input.height];

    int gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int gy[3][3] = {
        {-1,-2,-1},
        { 0, 0, 0},
        { 1, 2, 1}
    };

    for (int y = 1; y < input.height - 1; y++) {
        for (int x = 1; x < input.width - 1; x++) {

            int sumX = 0;
            int sumY = 0;

            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {

                    int idx = (y + dy) * input.width + (x + dx);
                    int pixel = input.data[idx].r;

                    sumX += pixel * gx[dy + 1][dx + 1];
                    sumY += pixel * gy[dy + 1][dx + 1];
                }
            }

            int edge = abs(sumX) + abs(sumY);
            if (edge > 255) edge = 255;

            int outIdx = y * input.width + x;
            output.data[outIdx].r = edge;
            output.data[outIdx].g = edge;
            output.data[outIdx].b = edge;
        }
    }

    return output;
}
