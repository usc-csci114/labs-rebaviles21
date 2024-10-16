#include <algorithm>
#include <cmath>
#include "shapes.h"

bool PointInTriangle(Point p, Point tri[3]) //returns a boolean and give the true or false if within the perimeter
{
	int s = (tri[0].x - tri[2].x) * (p.y - tri[2].y) - (tri[0].y - tri[2].y) * (p.x - tri[2].x);
	int t = (tri[1].x - tri[0].x) * (p.y - tri[0].y) - (tri[1].y - tri[0].y) * (p.x - tri[0].x);

	if ((s < 0) != (t < 0) && s != 0 && t != 0)
		return false;

	int d = (tri[2].x - tri[1].x) * (p.y - tri[1].y) - (tri[2].y - tri[1].y) * (p.x - tri[1].x);
	return d == 0 || (d < 0) == (s + t <= 0);
}

//Implement your shapes here

Shape::Shape(Color c)
{
    m_color = c;
}

void Shape::draw(uint8_t ***image, uint32_t h, uint32_t w)
{
    // to do the draw: each spae will have boolean getsize and boudning box (shape will have a color)
    // algorithm:

    BoundingBox bb = getBoundingBox(); // grabs bounding box
    for(int r =bb.ul.y ; r < bb.br.y; r++) {
        for(int c = bb.ul.x ; c < bb.br.x; c++) {
            if(inside(c,r)) { // colors in the corresponding area (bounding box) will be shaded if not associatied with shape
                image[r][c][0] = m_color.r;
                image[r][c][1] = m_color.g;
                image[r][c][2] = m_color.b;
            }
        }
    } 
}
Triangle::Triangle(Point t[3], Color c) : Shape(c)
{
    // initialize for the coordinates and the t variable
    m_tri[0] = t[0];
    m_tri[1] = t[1];
    m_tri[2] = t[2];
}
Triangle::~Triangle() {} // no need for anything because no memory was allocated
//error: initialize the base class for color
BoundingBox Triangle::getBoundingBox()
{
    BoundingBox b;
    // b.ul.x = min(m_tri[0].x, m_tri[1].x, m_tri[2].x);
    // b.ul.y = min(m_tri[0].y, m_tri[1].y, m_tri[2].y);

    // b.br.x = max(m_tri[0].x, m_tri[1].x, m_tri[2].x);
    // b.br.y = max(m_tri[0].y, m_tri[1].y, m_tri[2].y);
    //changed to account for min and max arguments (2)
    b.ul.x = min(m_tri[0].x, min(m_tri[1].x, m_tri[2].x));
    b.ul.y = min(m_tri[0].y, min(m_tri[1].y, m_tri[2].y));

    b.br.x = max(m_tri[0].x, max(m_tri[1].x, m_tri[2].x));
    b.br.y = max(m_tri[0].y, max(m_tri[1].y, m_tri[2].y));


    return b;
}

bool Triangle::inside(uint32_t x, uint32_t y ) 
{
    Point p = {x,y}; //uses the virtual functions and the bounding boxes
    return PointInTriangle(p, m_tri);
}
Circle::Circle(Point center, uint32_t r, Color c): Shape(c)
{
    m_center = center;
    m_radius = r;
}

Circle ::~Circle() {}
BoundingBox Circle::getBoundingBox() {
    BoundingBox b;
    b.ul.x = m_center.x - m_radius; 
    b.ul.y = m_center.y - m_radius;
    b.br.x = m_center.x + m_radius;
    b.br.y = m_center.y + m_radius;

    return b;

}

bool Circle::inside(uint32_t x, uint32_t y ) {
    double dx = x;
    double dy = y;
    double distance = sqrt((m_center.x - dx)*(m_center.x-2-dx)+ (m_center.y - dy)*(m_center.y-2-dy));

    return distance < m_radius;

}
//try to work on the hard code of the triangle if you finish the shape (constructor-- copy the color and then draw it out)
// for every pixel inside it and if they call the boolean shown in the beginning) 

Rectangle::Rectangle(Point r[4], Color c) :Shape(c) {
    m_rec[0] = r[0];
    m_rec[1] = r[1];
    m_rec[2] = r[2];
    m_rec[3] = r[3];

}

Rectangle::~Rectangle() {};

bool Rectangle::inside(uint32_t x, uint32_t y){
    double dx = x; //uses the virtual functions and the bounding boxes
    double dy = y;

} 
BoundingBox Rectangle::getBoundingBox() {

} //how do you get the bounding box for a triangle?

//getting an error with the linkage (-v)