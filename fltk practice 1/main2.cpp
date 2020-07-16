#include <iostream>
#include <cmath>
#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
#include "righttriangle.h"
using namespace Graph_lib;

int main()
{
	Point tl(100, 100);           // to become top left  corner of window

	Simple_window win(tl, 600, 400, "Righttriangle");    // make a simple window

	double x, y, a, b, angle;
	std::cin >> x >> y >> a >> b;
	angle = atan(b / a);
	Point AA, BB;
	AA.x = x - a * cos(angle);
	BB.y = AA.y = y - a * sin(angle);
	BB.x = AA.x + pow(a*a + b * b, 0.5);
	R r1(BB, AA, a, b, 0, angle);          // make a shape (a polygon)
	R r2(r1.return_A(), r1.return_B(), a, b, r1.return_angle(), angle);
	R r3(r2.return_A(), r2.return_B(), a, b, r2.return_angle(), angle);
	R r4(r3.return_A(), r3.return_B(), a, b, r3.return_angle(), angle);
	R r5(r4.return_A(), r4.return_B(), a, b, r4.return_angle(), angle);
	R r6(r5.return_A(), r5.return_B(), a, b, r5.return_angle(), angle);
	R r7(r6.return_A(), r6.return_B(), a, b, r6.return_angle(), angle);
	R r8(r7.return_A(), r7.return_B(), a, b, r7.return_angle(), angle);
	r1.set_color(Color::red);
	r2.set_color(Color::blue);
	r3.set_color(Color::black);
	r4.set_color(Color::magenta);
	r5.set_color(Color::dark_red);
	r6.set_color(Color::dark_blue);
	r7.set_color(Color::white);
	r8.set_color(Color::dark_magenta);

	win.attach(r1);
	win.attach(r2);
	win.attach(r3);
	win.attach(r4);
	win.attach(r5);
	win.attach(r6);
	win.attach(r7);
	win.attach(r8);


	win.wait_for_button();       // give control to the display engine

	return 0;
}
