#include "framereader.h"
#include<fstream>
#include<iostream>

FrameBuffer readPPM(const char* filename){
	FrameBuffer frame;
	frame.data=nullptr;
	frame.width=0;
	frame.height=0;
	std::ifstream file(filename, std::ios::binary);
	if(!file){
		std::cout<<"can not open file";
		return frame;
	}
	std::string format;
	file>>format;
	file>>frame.width>>frame.height;
	int maxval;
	file>>maxval;
	file.get();
	int total=frame.width * frame.height;
	frame.data=new Pixel[total];
	file.read((char*)frame.data,total*3);

	file.close();
	return frame;
}
