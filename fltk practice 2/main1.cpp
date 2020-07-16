#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
#include "BarChart.h"
//------------------------------------------------------------------------------
int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib
    Simple_window win(Point(100,100),1000,500,"BarChart");//窗口

    Axis ya(Axis::y,Point(30,400),360,18,"       temperature");//y轴
    ya.set_color(Color::black);

    Axis xa(Axis::x,Point(30,400),740,36,"                                                                                                                                    month");//x轴
    xa.set_color(Color::black);
    Text t1(Point(55,420),"Jan");
    t1.set_color(Color::blue);
    Text t2(Point(115,420),"Feb");
    t2.set_color(Color::blue);
    Text t3(Point(175,420),"Mar");
    t3.set_color(Color::blue);
    Text t4(Point(235,420),"Apr");
    t4.set_color(Color::blue);
    Text t5(Point(295,420),"May");
    t5.set_color(Color::blue);
    Text t6(Point(355,420),"Jun");
    t6.set_color(Color::blue);
    Text t7(Point(415,420),"Jul");
    t7.set_color(Color::blue);
    Text t8(Point(475,420),"Aug");
    t8.set_color(Color::blue);
    Text t9(Point(535,420),"Sept");
    t9.set_color(Color::blue);
    Text t10(Point(595,420),"Oct");
    t10.set_color(Color::blue);
    Text t11(Point(655,420),"Nov");
    t11.set_color(Color::blue);
    Text t12(Point(715,420),"Dec");
    t12.set_color(Color::blue);

    Text w1(Point(15,400),"0");
    w1.set_color(Color::blue);
    Text w2(Point(15,380),"2");
    w2.set_color(Color::blue);
    Text w3(Point(15,360),"4");
    w3.set_color(Color::blue);
    Text w4(Point(15,340),"6");
    w4.set_color(Color::blue);
    Text w5(Point(15,320),"8");
    w5.set_color(Color::blue);
    Text w6(Point(10,300),"10");
    w6.set_color(Color::blue);
    Text w7(Point(10,280),"12");
    w7.set_color(Color::blue);
    Text w8(Point(10,260),"14");
    w8.set_color(Color::blue);
    Text w9(Point(10,240),"16");
    w9.set_color(Color::blue);
    Text w10(Point(10,220),"18");
    w10.set_color(Color::blue);
    Text w11(Point(10,200),"20");
    w11.set_color(Color::blue);
    Text w12(Point(10,180),"22");
    w12.set_color(Color::blue);
    Text w13(Point(10,160),"24");
    w13.set_color(Color::blue);
    Text w14(Point(10,140),"26");
    w14.set_color(Color::blue);
    Text w15(Point(10,120),"28");
    w15.set_color(Color::blue);
    Text w16(Point(10,100),"30");
    w16.set_color(Color::blue);
    Text w17(Point(10,80),"32");
    w17.set_color(Color::blue);
    Text w18(Point(10,60),"34");
    w18.set_color(Color::blue);
    Text w19(Point(10,40),"36");
    w19.set_color(Color::blue);

    Text name(Point(300,440),"the temperature change with month in two places");
    name.set_color(Color::black);

    BarChart b1;//得到数据的类

    Lines x1;//第一个城市的图
    for(int i=0; i<12; i++)
    {
        x1.add(Point(50+i*60,400-b1.temp1[i+1]*10),Point(70+i*60,400-b1.temp1[i+1]*10));
        x1.add(Point(50+i*60,400-b1.temp1[i+1]*10),Point(50+i*60,400));
        x1.add(Point(70+i*60,400),Point(70+i*60,400-b1.temp1[i+1]*10));
        x1.add(Point(70+i*60,400),Point(50+i*60,400));
    }
    x1.set_color(Color::red);

    Lines x2;//第二个城市的图
    for(int i=0; i<12; i++)
    {
        x2.add(Point(70+i*60,400-b1.temp2[i+1]*10),Point(90+i*60,400-b1.temp2[i+1]*10));
        x2.add(Point(70+i*60,400-b1.temp2[i+1]*10),Point(70+i*60,400));
        x2.add(Point(90+i*60,400),Point(90+i*60,400-b1.temp2[i+1]*10));
        x2.add(Point(90+i*60,400),Point(70+i*60,400));
    }

    Lines x1_ex;
    x1_ex.add(Point(700,30),Point(730,30));
    x1_ex.add(Point(730,50),Point(730,30));
    x1_ex.add(Point(730,50),Point(700,50));
    x1_ex.add(Point(700,50),Point(700,30));
    x1_ex.set_color(Color::red);

    Text x1_qw(Point(740,50),"Austin");
    x1_qw.set_color(Color::red);

    Lines x2_ex;
    x2_ex.add(Point(700,60),Point(730,60));
    x2_ex.add(Point(730,80),Point(730,60));
    x2_ex.add(Point(730,80),Point(700,80));
    x2_ex.add(Point(700,80),Point(700,60));
    x2_ex.set_color(Color::cyan);

    Text x2_qw(Point(740,80),"NewYork");
    x2_qw.set_color(Color::cyan);

    x2.set_color(Color::cyan);
    win.attach(x1);
    win.attach(x2);

    win.attach(xa);
    win.attach(ya);
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
    win.attach(xa);
    win.attach(ya);
    win.attach(w1);
    win.attach(w2);
    win.attach(w3);
    win.attach(w4);
    win.attach(w5);
    win.attach(w6);
    win.attach(w7);
    win.attach(w8);
    win.attach(w9);
    win.attach(w10);
    win.attach(w11);
    win.attach(w12);
    win.attach(w13);
    win.attach(w14);
    win.attach(w15);
    win.attach(w16);
    win.attach(w17);
    win.attach(w18);
    win.attach(w19);
    win.attach(x1);
    win.attach(x2);
    win.attach(name);
    win.attach(x1_ex);
    win.attach(x1_qw);
    win.attach(x2_ex);
    win.attach(x2_qw);




    win.wait_for_button();

    return 0;
}

//------------------------------------------------------------------------------
