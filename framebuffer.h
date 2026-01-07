#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H
#include "pixel.h"

struct FrameBuffer{
	Pixel* data;
	int width;
	int height;
};
#endif
