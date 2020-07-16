#include <iostream>
#include <cmath>
#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
using namespace Graph_lib;

struct R :Shape{
	int a, b, c;
	Point A, B, C;
	double ang,ang_b;
	void add(Point p) { Shape::add(p); }
	R(Point AA, Point BB, int aa, int bb, double angle, double angle_b)
	{
		B = BB;
		A = AA;
		a = aa;
		b = bb;
		c = pow(a*a + b * b, 0.5);
		ang = angle;
		ang_b = angle_b;
		C.x = B.x + a * cos(-(ang+ang_b));
		C.y = B.y - a * sin(-(ang+ang_b));
		add(A);
		add(B);
		add(C);
		add(A);
		add(B);
		add(C);
	}
	void draw_lines() const
	{
		if (color().visibility())
			for (int i = 1; i < number_of_points(); i += 2)
				fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
	}
	Point return_A()
	{
		Point tmp;
		tmp.x = A.x + c*cos(-ang - 0.785);
		tmp.y = A.y -c*sin(-ang - 0.785);
		return tmp;
	}
	Point return_B() { return A; }
	int return_a() { return a; }
	int return_b() { return b; }
	double return_angle(){ return ang + 0.785; }
};
