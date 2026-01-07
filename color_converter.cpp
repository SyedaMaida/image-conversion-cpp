#include "color_converter.h"

FrameBuffer rgbToGray(const FrameBuffer& input){
	FrameBuffer output;
	output.width=input.width;
	output.height=input.height;
	int total=input.width*input.height;
	output.data=new Pixel[total];
	for ( int i=0;i<total;i++){
		uint8_t gray=(30*input.data[i].r + 59*input.data[i].g +11*input.data[i].b)/100;
		output.data[i].r=gray;
		output.data[i].g=gray;
		output.data[i].b=gray;
	}
	return output;
}
