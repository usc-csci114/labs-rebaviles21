#include <iostream>
#include "bmplib.h"
#include "shapes.h"

using namespace std;

uint8_t*** newImage(uint8_t bground[3], uint32_t h, uint32_t w)
{
	uint8_t*** img = new uint8_t**[h];
	for(int r=0; r < h; r++) {
		img[r] = new uint8_t*[w];
		for(int c = 0; c < w; c++) {
			img[r][c] = new uint8_t[3];
			img[r][c][0] = bground[0];
			img[r][c][1] = bground[1];
			img[r][c][2] = bground[2];
		}
	}
	return img;
}

int main(int argc, char* argv[])
{
	uint8_t bg[] = {255,255,255};
	uint8_t*** image = newImage(bg, 1024, 1024);
	
	//add your code here
	Point p1 = {10,10};
	Point p2 = {110,10};
	Point p3 = {110,110};
	Point points[3] = {p1,p2,p3};
	Color red = {255,0,0};
	Triangle tri(points, red);
	tri.draw(image,1024,1024);

	Color blue = {0,0,255};
	Point center = {512,512};
	int rad = 200;
	Circle circle(center,rad,blue);
	circle.draw(image, 1024,1024);

	//rectangles code
	Color reds = {0,255,0};
	Point t1 = {10,20};
	Point t2 = {110,20};
	Point t3 = {10,70};
	Point t4 = {110,70};
	Point recPoints[4] = {t1,t2,t3,t4};
	Rectangle rec(recPoints, reds);
	rec.draw(image,1024,1024);
	//ask the user what shape the want to draw
	//collect the required information
	//instantiate the shape, draw it into the image
	//loop and ask for another shape, "quit" to stop

	// Circle red = {0,0,255};
	
	writeRGBBMP("output.bmp", image, 1024, 1024);
}
