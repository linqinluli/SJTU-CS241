#include "Graph.h"
#include "Simple_window.h"
#include<ctime>
#include <cstdio>
#include<windows.h>
#include<cmath>
#include<string>
#include<cstring>
#include<iostream>

int main()
{
    using namespace Graph_lib;
    Point tl(100, 100);           // to become top left  corner of window
    Simple_window win(tl, 600, 400, "AnalogClock");    // make a simple window

    Lines x;//刻度
    x.add(Point(375,330),Point(370,321));
    x.add(Point(430,275),Point(421,270));
    x.add(Point(375,70),Point(370,79));
    x.add(Point(225,330),Point(230,321));
    x.add(Point(225,70),Point(230,79));
    x.add(Point(170,275),Point(179,270));
    x.add(Point(170,125),Point(179,130));
    x.add(Point(430,125),Point(421,130));
    x.add(Point(300,60),Point(300,50));
    x.add(Point(150,200),Point(160,200));
    x.add(Point(300,350),Point(300,340));
    x.add(Point(450,200),Point(440,200));
    x.set_color(Color::black);
    Text t1(Point(360,89.4),"1");
    t1.set_color(Color::black);
    Text t2(Point(410.6,141),"2");
    t2.set_color(Color::black);
    Text t3(Point(427,205),"3");
    t3.set_color(Color::black);
    Text t4(Point(408.6,269),"4");
    t4.set_color(Color::black);
    Text t5(Point(362,317.6),"5");
    t5.set_color(Color::black);
    Text t6(Point(297,335),"6");
    t6.set_color(Color::black);
    Text t7(Point(234,315.6),"7");
    t7.set_color(Color::black);
    Text t8(Point(186.4,270),"8");
    t8.set_color(Color::black);
    Text t9(Point(168,205),"9");
    t9.set_color(Color::black);
    Text t10(Point(181.4,140),"10");
    t10.set_color(Color::black);
    Text t11(Point(230,92.4),"11");
    t11.set_color(Color::black);
    Text t12(Point(295,75),"12");
    t12.set_color(Color::black);

    Circle c(Point(300,200),150);
    c.set_color(Color::black);

    win.attach(x);
    win.attach(c);
    win.attach(t1);
    win.attach(t2);
    win.attach(t3);
    win.attach(t4);
    win.attach(t5);
    win.attach(t6);
    win.attach(t7);
    win.attach(t8);
    win.attach(t9);
    win.attach(t10);
    win.attach(t11);
    win.attach(t12);

    while(true)
    {

        time_t rawtime;//获得系统时间
        struct tm *t;
        time(&rawtime);
        t = localtime(&rawtime);
        int year=t->tm_year+1900;
        int month=t->tm_mon+1;
        int day=t->tm_mday;
        int hour=t->tm_hour;
        int min=t->tm_min;
        int sec=t->tm_sec;
        int all_t=60*hour+min;
        string sdate=std::to_string(year)+"/"+std::to_string(month)+"/"+std::to_string(day);
        string stime=std::to_string(hour)+":"+std::to_string(min)+":"+std::to_string(sec);
        if(hour>12)
            hour-=12;
        Line sec_point(Point(300,200),Point (300+120*cos(-3.1415926/2+3.1415926*sec/30.0),200+120*sin(-3.1415926/2+3.1415926*sec/30.0)));
        Line min_point(Point(300,200),Point (300+100*cos(-3.1415926/2+3.1415926*min/30.0),200+100*sin(-3.1415926/2+3.1415926*min/30.0)));
        Line hour_point(Point(300,200),Point (300+80*cos(-3.1415926/2+3.1415926*all_t/360.0),200+80*sin(-3.1415926/2+3.1415926*all_t/360.0)));
        Text show_date(Point(267,250),sdate);
        show_date.set_color(Color::black);
        Text show_time(Point(275,265),stime);
        show_time.set_color(Color::black);

        sec_point.set_color(Color::black);
        min_point.set_color(Color::cyan);
        hour_point.set_color(Color::red);
        win.attach(sec_point);
        win.attach(min_point);
        win.attach(hour_point);
        win.attach(show_date);
        win.attach(show_time);

        Sleep(1000);
        win.redraw();
        Fl::wait();
    }




    return 0;
}
