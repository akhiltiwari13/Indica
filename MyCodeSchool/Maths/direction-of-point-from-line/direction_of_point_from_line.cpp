// determines if a point is "on the line" / "to the left of it"/ "or to the right of it".
#include <iostream>
#include <math.h>

using namespace std;

struct point{
	double x;
	double y;
};

// if cross_prodcut is NEGATIVE then the point is to the RIGHT of the line segment.
double cross_product(point p1, point p2)
{
	return  ((p1.x*p2.y)-(p1.y*p2.x));
}

// inorder for the cross product to make sense, we need to shift one of the ends to the line segment so as to make it the origin.
point subtract(point source, point origin)
{
	point result;
	result.x= source.x - origin.x;
	result.y= source.y - origin.y;
	return result;
}


int main(void)
{
	point a={-30,10};
	point b={29,-15};
	point p={15, 28};

	// shifting the cartesian plane so a becomes the origin.
	a = subtract(a, a);
	b = subtract(b, a);
	p = subtract(p, a);

	if(cross_product(p,b)<0)
		cout<<"point is to the left"<<endl;
	else if(cross_product(p,b)>0)
		cout<<"point is to the right"<<endl;
	else
		cout<<"point is on the line"<<endl;
	return 0;
}

