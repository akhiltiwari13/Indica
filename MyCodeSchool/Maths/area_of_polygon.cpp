#include <iostream>
#include <math.h>

using namespace std;

struct point{
	double x;
	double y;
};

double cross_product(point p1, point p2)
{
	return  ((p1.x*p2.y)-(p1.y*p2.x));
}

// a cross product can be used to find the area of a triangle, whose one of the vertex is the origin.
double area_of_an_origin_triange(point p1, point p2)
{
	return abs(cross_product(p1,p2)/2);
}

// this formula can be used to calculate the area of a triangle which may or may not enclose the origin.
// cross product of a clockwise direction is NEGATIVE.
// cross product of a counter clockwise direction is POSITIVE.
double area_of_generic_triangle(point p1, point p2, point p3)
{
	return abs((cross_product(p1,p2) + cross_product(p2, p3) + cross_product(p3,p1))/2.0);
}

double area_of_generic_polygon(point vertices[] , int size)
{
	int area=0;
	for(int i=0; i<size; i++)
	{
		area+= cross_product(vertices[i], vertices[(i+1)%size])/2;
	}
	return abs(area);
}

int main(void)
{
	point p1={0,0};
	point p2={4,0};
	point p3={4,4};
	point p4={0,4};
	point vertices[]= {p1, p2, p3, p4};
	cout<<"area: "<<area_of_generic_polygon(vertices, 4)<<endl;
	return 0;
}
