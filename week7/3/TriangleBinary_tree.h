#include "Graph.h"
#include "Simple_window.h"
#include <cmath>
#include<iostream>


using namespace Graph_lib;

class Ttree:public btree
{
     int N;
public:
    Ttree(int n=0)
    {
        N=n;
    }
    void getn()
    {
        cout<<"Please input the level and the biggest level of TraiangleBinary is 5."<<endl;
        cin>>N;
    }
    void draw()
    {
        Lines x;
        for(int i=0; i<N; i++)
        {
            if(i==0)
            {
                x.add(Point(450,0),Point(438.45,20));
                x.add(Point(450,0),Point(461.55,20));
                x.add(Point(438.45,20),Point(461.55,20));
                x.draw_lines();
            }
            if(i==1)
            {
                int dx=(20*(pow(2,N-1)-1+pow(2,N-1)*2))/(pow(2,i-1)+1+pow(2,i-1)*2);
                x.add(Point(450,20),Point(450+dx*0.5,30));
                x.add(Point(450,20),Point(450-dx*0.5,30));

            }

            if(i>=1)
            {
                int dx=(20*(pow(2,N-1)-1+pow(2,N-1)*2))/(pow(2,i-1)+1+pow(2,i-1)*2);
                int last_dx=(20*(pow(2,N-1)-1+pow(2,N-1)*2))/(pow(2,i-2)+1+pow(2,i-2)*2);
                for(int j=pow(2,i-1); j>0; j--)
                {
                    x.add(Point(450+dx*(j-0.5),30*i),Point(461.55+dx*(j-0.5),30*i+20));
                    x.add(Point(450+dx*(j-0.5),30*i),Point(438.15+dx*(j-0.5),30*i+20));
                    x.add(Point(461.55+dx*(j-0.5),30*i+20),Point(438.15+dx*(j-0.5),30*i+20));
                    if(i>1)
                    {
                        x.add(Point(450+dx*(j-0.5),30*i),Point(450+last_dx*((j+1)/2-0.5),30*i-10));
                        x.draw_lines();
                    }

                }
                for(int j=pow(2,i-1); j>0; j--)
                {
                    x.add(Point(450-dx*(j-0.5),30*i),Point(461.55-dx*(j-0.5),30*i+20));
                    x.add(Point(450-dx*(j-0.5),30*i),Point(438.15-dx*(j-0.5),30*i+20));
                    x.add(Point(461.55-dx*(j-0.5),30*i+20),Point(438.15-dx*(j-0.5),30*i+20));
                    if(i>1)
                    {
                        x.add(Point(450-dx*(j-0.5),30*i),Point(450-last_dx*((j+1)/2-0.5),30*i-10));
                        x.draw_lines();
                    }

                }
            }
        }
    }
};
