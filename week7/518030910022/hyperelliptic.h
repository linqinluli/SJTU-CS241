#include "Graph.h"
#include "Simple_window.h"
#include <iostream>
#include <cmath>
using namespace Graph_lib;
class hype
{
    double a=0,b=0,m=0,n=0,N=0;
public:
    hype(double a1=0,double b1=0,double m1=0,double n1=0,double N1=1)
    {
        a=a1;
        b=b1;
        m=m1;
        n=n1;
        N=N1;
    }

    void input()
    {
        cin>>a>>b>>m>>n>>N;
    }
    double get_y(double numx)
    {
        double tmp=1-pow(abs(numx/a),m);
        double res=b*pow(abs(tmp),1/n);
        return res;
    }
    void show_hyoe()
    {
        Point tl(100,100);
        Simple_window win(tl,600,400,"hyperelliptic");

        double dx=4.0*a/N;
        Lines x;
        win.attach(x);
        for(int i=0; i<=N/2; i++)
            for(int j=i+1; j<=N/2; j++)
            {
                x.add(Point(100+i*dx,b+50+get_y(i*dx-a)),Point(100+j*dx,b+50+get_y(j*dx-a)));
                x.add(Point(100+i*dx,b+50-get_y(i*dx-a)),Point(100+j*dx,b+50-get_y(j*dx-a)));
                x.add(Point(100+i*dx,b+50+get_y(i*dx-a)),Point(100+j*dx,b+50-get_y(j*dx-a)));
                x.add(Point(100+i*dx,b+50-get_y(i*dx-a)),Point(100+j*dx,b+50+get_y(j*dx-a)));
            }

        win.wait_for_button();

    }

};

