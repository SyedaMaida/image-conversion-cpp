#include <iostream>
#include "framebuffer.h"
#include "framereader.h"
#include "color_converter.h"
#include "filters.h"
#include "edge.h"
#include "writer.h"

int main() {

    //read ip img
    FrameBuffer input = readPPM("input.ppm");
    if (!input.data) {
        std::cout << "Failed to read input image\n";
        return 1;
    }

    //convert to grayscale
    FrameBuffer grayImage = rgbToGray(input);
    writePPM_P6("gray.ppm",grayImage);

    // Filter
    FrameBuffer smoothImage = smoothFilter(grayImage);
    writePPM_P6("smooth.ppm",smoothImage);
    // edge detection
    FrameBuffer edgeImage = edge(smoothImage);
   // writePPM("edge.ppm",edgeImage);


    // wite output image
    writePPM_P6("output.ppm", edgeImage);

    std::cout << "Pipeline finished! Output saved as output.ppm\n";

    delete[] input.data;
    delete[] grayImage.data;
    delete[] smoothImage.data;
    delete[] edgeImage.data;

    return 0;
}
