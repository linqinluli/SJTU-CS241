#include <iostream>
#include<fstream>
#include<string>
#include <cmath>

class BarChart
{
public:
    double temp1[13]= {0};
    double temp2[13]= {0};
    BarChart()
    {
        ifstream in;
        double data=0;
        int i=0,month=0;
        char str[20];
        in.open("Austin.csv");
        in.getline(str,20);
        while(in.getline(str,20))
        {
            month=stod(str+5);
            for(i=0; str[i]!=','; i++);
            data=stod(str+i+1);
            temp1[month]+=data;
        }
        for(int i=0; i<13; i++)
        {
            if(i==2)
            {
                temp1[i]/=29.0;
                continue;
            }
            if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
                temp1[i]/=31.0;
            else
                temp1[i]/=30.0;
        }
        in.close();
        in.open("NewYork.csv");
        in.getline(str,20);
        while(in.getline(str,20))
        {
            month=stod(str+5);
            for(i=0; str[i]!=','; i++);
            data=stod(str+i+1);
            temp2[month]+=data;
        }
        for(int i=0; i<13; i++)
        {
            if(i==2)
            {
                temp2[i]/=29.0;
                continue;
            }
            if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
                temp2[i]/=31.0;
            else
                temp2[i]/=30.0;
        }
        in.close();
    }
};
