#ifndef DATA_STATISTICS_AND_VISUALIZATION_H_INCLUDED
#define DATA_STATISTICS_AND_VISUALIZATION_H_INCLUDED

#include<fstream>
#include<string>
#include<iostream>
#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities

struct data
{
    double latitude;
    double longitude;
    int price=0;
    int minimum_nights;
    int number_of_reviews;
    int reviews_per_month;
    int calculated_host_listings_count;
    int availability_365;
    int neighbour=0;

};
const int N=40000;

class dsv
{
    data room[N];
    int roomnum;
    int num_of_queens=0;
    int num_of_manhattan=0;
    int num_of_staten=0;
    int num_of_bronx=0;
    int num_of_brooklyn=0;
    double bronx_pedicite_prcie[10000];
    double a_of_unary;
    bool isok_Unary_linear_regression;
    double b_of_unary;
    double r_of_unary;
public:
    void getdsv()
    {
        using namespace std;
        char str[1000];
        ifstream in;
        in.open("AB_NYC_2019.csv");
        if(!in)
        {
            cout<<"Open File Fail."<<endl;
            exit(1);
        }
        in.getline(str,1000);
        int position_num=0,room_num=0;
        for(int i=0; i<40000; i++)
        {
            in.getline(str,1000);

            int position_arry[200]= {0};
            int j=0;
            position_num=0;
            while(str[j]!='\n')
            {
                if(str[j]==','&&str[j+1]=='4'&&str[j+2]=='0'&&str[j+3]=='.')
                    position_num=5;
                if(str[j]=='B'&&str[j+1]=='r'&&str[j+2]=='o'&&str[j+3]=='o'&&str[j+4]=='k')
                    room[room_num].neighbour=1;
                if(str[j]=='B'&&str[j+1]=='r'&&str[j+2]=='o'&&str[j+3]=='n'&&str[j+4]=='x')
                    room[room_num].neighbour=2;
                if(str[j]=='M'&&str[j+1]=='a'&&str[j+2]=='n'&&str[j+3]=='h'&&str[j+4]=='a')
                    room[room_num].neighbour=3;
                if(str[j]=='Q'&&str[j+1]=='u'&&str[j+2]=='e'&&str[j+3]=='e'&&str[j+4]=='n')
                    room[room_num].neighbour=4;
                if(str[j]=='S'&&str[j+1]=='t'&&str[j+2]=='a'&&str[j+3]=='t'&&str[j+4]=='e')
                    room[room_num].neighbour=5;

                if(str[j]==',')
                {
                    position_arry[position_num]=j;
                    position_num++;
                }
                j++;
            }
            if(stod(str+position_arry[8]+1)>2000||stod(str+position_arry[8]+1)==0)
                continue;
            if(stod(str+position_arry[10]+1)==0)
                continue;
            room[room_num].latitude=stod(str+position_arry[5]+1);
            room[room_num].longitude=stod(str+position_arry[6]+1);
            room[room_num].price=stod(str+position_arry[8]+1);
            room[room_num].reviews_per_month=stod(str+position_arry[12]+1);
            room[room_num].minimum_nights=stod(str+position_arry[9]+1);
            room[room_num].number_of_reviews=stod(str+position_arry[10]+1);
            room[room_num].calculated_host_listings_count=stod(str+position_arry[13]+1);
            room[room_num].availability_365=stod(str+position_arry[14]+1);

            room_num++;
        }
        roomnum=room_num;
    }
    void show_map()
    {
        using namespace Graph_lib;
        Simple_window win(Point(100,100),800,800,"NEW YORK");//´°¿Ú
        Image NY(Point(0,0),"NY.jpg");

        NY.draw_lines();
        for(int i=0; i<40000; i++)
        {
            Circle c(Point(1400*(room[i].longitude+74.25915),775-1800*(room[i].latitude-40.491952)),3);
            if(room[i].neighbour==1)
                c.set_color(Color::red);
            if(room[i].neighbour==2)
                c.set_color(Color::green);
            if(room[i].neighbour==3)
                c.set_color(Color::black);
            if(room[i].neighbour==4)
                c.set_color(Color::blue);
            if(room[i].neighbour==5)
                c.set_color(Color::yellow);
            c.draw();
            win.attach(c);

        }
        win.wait_for_button();
    }
    void show_graph_1()
    {
        int brooklyn_price[200]= {0};
        int bronx_price[200]= {0};
        int manhattan_price[200]= {0};
        int queens_price[200]= {0};
        int staten_price[200]= {0};
        using namespace Graph_lib;
        Simple_window win(Point(100,100),1200,700,"NEW YORK");

        for(int i=0; room[i].price!=0; i++)
        {
            if(room[i].neighbour==1)
            {
                brooklyn_price[room[i].price/10]++;
            }
            if(room[i].neighbour==2)
            {
                bronx_price[room[i].price/10]++;
            }
            if(room[i].neighbour==3)
            {
                manhattan_price[room[i].price/10]++;
            }
            if(room[i].neighbour==4)
            {
                queens_price[room[i].price/10]++;
            }
            if(room[i].neighbour==5)
            {
                staten_price[room[i].price/10]++;
            }
        }

        Axis ya(Axis::y,Point(10,600),580,6,"       Count");//y轴
        ya.set_color(Color::black);

        Axis xa(Axis::x,Point(10,600),1200,10,"                                                              Price");//x轴
        xa.set_color(Color::black);

        Lines brooklyn ;
        Lines bronx ;
        Lines manhattan;
        Lines queens ;
        Lines staten ;
        for(int i=0; i<200; i++)
        {
            brooklyn.add(Point(20*i+10,600-brooklyn_price[i]/5),Point(20*i+30,600-brooklyn_price[i+1]/5));
        }
        for(int i=0; i<200; i++)
        {
            bronx.add(Point(20*i+10,600-bronx_price[i]/5),Point(20*i+30,600-bronx_price[i+1]/5));
        }
        for(int i=0; i<200; i++)
        {
            manhattan.add(Point(20*i+10,600-manhattan_price[i]/5),Point(20*i+30,600-manhattan_price[i+1]/5));
        }
        for(int i=0; i<200; i++)
        {
            queens.add(Point(20*i+10,600-queens_price[i]/5),Point(20*i+30,600-queens_price[i+1]/5));
        }
        for(int i=0; i<200; i++)
        {
            staten.add(Point(20*i+10,600-staten_price[i]/5),Point(20*i+30,600-staten_price[i+1]/5));
        }
        brooklyn.set_color(Color::red);
        bronx.set_color(Color::green);
        queens.set_color(Color::black);
        manhattan.set_color(Color::blue);
        staten.set_color(Color::yellow);

        Text city1(Point(800,200),"Red-----------Brooklyn");
        Text city2(Point(800,220),"Green---------Bronx");
        Text city3(Point(800,240),"Black---------Queens");
        Text city4(Point(800,260),"Blue----------Manhattan");
        Text city5(Point(800,280),"Yellow--------Staten");

        Text t1(Point(130-10,620),"60");
        Text t2(Point(250-10,620),"120");
        Text t3(Point(370-10,620),"180");
        Text t4(Point(490-10,620),"240");
        Text t5(Point(610-10,620),"300");
        Text t6(Point(730-10,620),"360");
        Text t7(Point(850-10,620),"420");
        Text t8(Point(970-10,620),"480");
        Text t9(Point(1080,620),"540");
        Text t10(Point(1200,620),"600");
        Text t0(Point(10,620),"0");
        Text y2(Point(20,510),"500");
        Text y3(Point(20,415),"1000");
        Text y4(Point(20,320),"1500");
        Text y5(Point(20,225),"2000");
        Text y6(Point(20,130),"2500");
        Text y7(Point(20,30),"3000");
        Text t10086(Point(600,350),"Price Distribution in Five Regions");

        city1.set_color(Color::red);
        city2.set_color(Color::green);
        city3.set_color(Color::black);
        city4.set_color(Color::blue);
        city5.set_color(Color::yellow);
        t1.set_color(Color::black);
        t2.set_color(Color::black);
        t3.set_color(Color::black);
        t4.set_color(Color::black);
        t5.set_color(Color::black);
        t6.set_color(Color::black);
        t7.set_color(Color::black);
        t8.set_color(Color::black);
        t9.set_color(Color::black);
        t10.set_color(Color::black);
        t0.set_color(Color::black);
        t10086.set_color(Color::blue);
        t10086.set_font_size(30);

        y2.set_color(Color::black);
        y3.set_color(Color::black);
        y4.set_color(Color::black);
        y5.set_color(Color::black);
        y6.set_color(Color::black);
        y7.set_color(Color::black);

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
        win.attach(t0);
        win.attach(city1);
        win.attach(city2);
        win.attach(city3);
        win.attach(city4);
        win.attach(city5);


        win.attach(y2);
        win.attach(y3);
        win.attach(y4);
        win.attach(y5);
        win.attach(y6);
        win.attach(y7);
        win.attach(bronx);
        win.attach(brooklyn);
        win.attach(queens);
        win.attach(manhattan);
        win.attach(staten);
        win.attach(ya);
        win.attach(xa);
        win.attach(t10086);
        win.redraw();
        Fl::wait();

        win.wait_for_button();

    };
    void show_graph_2()
    {
        using namespace Graph_lib;
        Simple_window win(Point(100,100),1200,700,"NEW YORK");

        Axis ya(Axis::y,Point(70,600),500,5,"       price");//y轴
        ya.set_color(Color::black);

        Axis xa(Axis::x,Point(70,600),1000,15,"                                                              number_of_reviews");//x轴
        xa.set_color(Color::black);

        xa.draw();
        ya.draw();
        for(int i=0; i<roomnum; i++)
        {
            Circle c(Point(70+room[i].number_of_reviews*1.5,600-room[i].price/5),3);
            c.set_color(Color::red);
            c.draw();

        }
        Text t1(Point(47,600+15),"0");
        Text t2(Point(37,500+5),"500");
        Text t3(Point(37,400+5),"1000");
        Text t4(Point(37,300+5),"1500");
        Text t5(Point(37,200+5),"2000");
        Text x1(Point(395,615),"200");
        Text x2(Point(720,615),"400");
        Text x3(Point(1050,615),"600");
        Text title(Point(400,300),"Price-Reviews Scatter Figure");

        x1.set_color(Color::black);
        x2.set_color(Color::black);
        x3.set_color(Color::black);
        t1.set_color(Color::black);
        t2.set_color(Color::black);
        t3.set_color(Color::black);
        t4.set_color(Color::black);
        t5.set_color(Color::black);
        title.set_color(Color::blue);
        title.set_font_size(50);
        t1.draw();
        t2.draw();
        t3.draw();
        t4.draw();
        t5.draw();
        x1.draw();
        x2.draw();
        x3.draw();
        title.draw();

        win.wait_for_button();
    }
    void Multiple_linear_regression()
    {
        int counts=0;
        for(int i=30000; i<roomnum; i++)
        {
            bronx_pedicite_prcie[counts++]=1.60345588e+02*room[i].latitude-6.84218346e+02*room[i].longitude-1.50842297e-01*room[i].minimum_nights-1.43023417e-01*room[i].number_of_reviews+3.39119434e-01*room[i].reviews_per_month+1.67945419e-01*room[i].calculated_host_listings_count+1.34275895e-01*room[i].availability_365-57002.253235694516;
        };
    }
    void Unary_linear_regression()
    {
        using namespace std;
        double x_sum=0,y_sum=0,x_avg=0,y_avg=0,lxy=0,lxx=0,lyy=0,a,b,r=0;
        int count=0;
        for(int i=0; i<roomnum; i++)
        {
            if(room[i].neighbour!=5)
            {
                x_sum+=room[i].number_of_reviews;
                y_sum+=room[i].price;
                count++;
            }
        }
        x_avg=x_sum/count;
        y_avg=y_sum/count;
        for(int i=0; i<count; i++)
        {
            lxy+=(room[i].number_of_reviews-x_avg)*(room[i].price-y_avg);
            lxx+=(room[i].number_of_reviews-x_avg)*(room[i].number_of_reviews-x_avg);
            lyy+=(room[i].price-y_avg)*(room[i].price-y_avg);
        }
        b=lxy/lxx;
        a=y_avg-b*x_avg;

        r=lxy/sqrt(lxx*lyy);
        r_of_unary=-r;
        a_of_unary=a;
        b_of_unary=b;

    }
    void show_prdict()
    {
        Unary_linear_regression();
        Multiple_linear_regression();

        using namespace Graph_lib;
        Simple_window win(Point(100,100),1200,700,"NEW YORK");

        Axis ya(Axis::y,Point(70,600),500,5,"       price");//y轴
        ya.set_color(Color::black);

        Axis xa(Axis::x,Point(70,600),1000,15,"                                                              number_of_reviews");//x轴
        xa.set_color(Color::black);

        xa.draw();
        ya.draw();

        double mse_unary=0;
        double mse_multiple=0;
        double sum_y=0,sum_prdy=0;int j=0;
        for(int i=30000; i<roomnum; i++)
        {
            sum_y+=room[i].price;
            sum_prdy+=bronx_pedicite_prcie[j];
        }
        j=0;
        sum_y=sum_y/(roomnum-30000);
        sum_prdy=sum_prdy/(roomnum-30000);
        for(int i=30000; i<roomnum; i++)
        {
            Circle c(Point(70+room[i].number_of_reviews*10,600-room[i].price/2),3);
            c.set_color(Color::red);
            c.draw();
            Circle p(Point(70+room[i].number_of_reviews*10,600-bronx_pedicite_prcie[j]/2),3);
            p.set_color(Color::blue);
            p.draw();
            Circle o(Point(70+room[i].number_of_reviews*10,600-(b_of_unary*room[i].number_of_reviews+a_of_unary)/2),3);
            o.set_color(Color::black);
            o.draw();
            mse_multiple+=(room[i].price-bronx_pedicite_prcie[j])*(room[i].price-bronx_pedicite_prcie[j]);
            mse_unary+=(room[i].price-sum_y)*(room[i].price-sum_y);
            j++;
        }
        double result=0;
        result=mse_multiple/(mse_unary);

        Text t1(Point(47,600+15),"0");
        Text t2(Point(37,500+5),"200");
        Text t3(Point(37,400+5),"400");
        Text t4(Point(37,300+5),"600");
        Text t5(Point(37,200+5),"800");
        Text x1(Point(395,615),"50");
        Text x2(Point(720,615),"100");
        Text x3(Point(1050,615),"150");
        Text title(Point(300,200),"Scatter Plot of Predicted and Actual Values for Some Data");
        Text y1(Point(500,300),"Red rings   O---Actual value");
        Text y2(Point(500,330),"Black rings O---Univariate linear regression prediction");
        Text y3(Point(500,360),"Blue rings  O---Multiple linear regression prediction");
        Text mse1(Point(500,390),"Person Correlation Coefficientof Univariate linear regression prediction:"+to_string(r_of_unary));
        Text mse2(Point(500,410),"Adjusted R-Square of Multiple linear regression prediction:"+to_string(1-result*(roomnum-30000)/(roomnum-29500)));

        mse1.set_color(Color::black);
        mse2.set_color(Color::black);
        y1.set_color(Color::red);
        y2.set_color(Color::black);
        y3.set_color(Color::blue);

        x1.set_color(Color::black);
        x2.set_color(Color::black);
        x3.set_color(Color::black);
        t1.set_color(Color::black);
        t2.set_color(Color::black);
        t3.set_color(Color::black);
        t4.set_color(Color::black);
        t5.set_color(Color::black);
        title.set_color(Color::blue);
        title.set_font_size(30);
        t1.draw();
        t2.draw();
        t3.draw();
        t4.draw();
        t5.draw();
        x1.draw();
        x2.draw();
        x3.draw();
        y1.draw();
        y2.draw();
        y3.draw();
        mse1.draw();
        mse2.draw();
        title.draw();

        win.wait_for_button();
    }
};

#endif // DATA_STATISTICS_AND_VISUALIZATION_H_INCLUDED
