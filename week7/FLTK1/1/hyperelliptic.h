//#include <FL/fl_draw.H>
#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities

using namespace Graph_lib;

class hype
{
    double a=0,b=0,m=0,n=0,N=0;
    hype(a1=0,b1=0,m1=0,n1=0,N1=1)
    {
        a=a1;
        b=b1;
        m=m1;
        n=n1;
        N=N1;
    }
public:
    void input()
    {
        cin>>a>>b>>m>>n>>N;
    }
    void show_hyoe()
    {
        double dx=4.0*a/N;
        lines x;
        x.add();

    }

};
