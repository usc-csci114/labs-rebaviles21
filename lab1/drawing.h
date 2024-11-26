#ifndef DRAWING_H
#define DRAWING_H


#include <string>
#include <vector>
#include "bmplib.h"

using namespace std;

//Define your structs/classes in this file

struct ColorPixel {
	uint8_t red, green, blue;
};

class ColorImage {
	public:
		ColorImage(uint32_t xdim, uint32_t ydim);
		void setPixel(ColorPixel p, uint32_t x, uint32_t y);
		ColorPixel getPixel(uint32_t x, uint32_t y);
		void render(string filename);
			
	private:
		vector< vector<ColorPixel> > data;
}; 

struct Point {
	double x, y;
};
struct Line {
	Point start, end;
	ColorPixel c;
};
class Drawing { //abstract model of the drawing
	public:
		Drawing(); // what do you initialize (have not grabbed for file) -- ColorImage = ColorImage(variables)
		void parse(string filename);
		void draw(); // go throught vector of lines and will give to line drawing algorithm (plotline) ;; return vector of points an set to colors
		void write(string filename); //calls render
	private:
		ColorImage image;
		vector<Line> lines;
		uint32_t xdim;
		uint32_t ydim;\
};

#endif