#include <iostream>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std;
void output(double x)
{
    int temp=int(x*10000);
    cout<<fixed<<setprecision(4)<< double(temp)/10000;
}
bool check(char *check1)
{
    for(int che=0; check1[che]!='\0'; che++)
        if(check1[che]!='-'&&check1[che]!='.'&&(check1[che]>'9'||check1[che]<'0'))
            return false;
    return true;
}
int main()
{
    double x[10]= {0},y[10]= {0},tar=0,r=0;
    int i=0;
    char* check1,*check2;
    check1=new char[10];
    check2=new char[10];
    cin.getline(check1,10);
    if(check(check1)==false)
    {
        cout<<"error"<<endl<<"error"<<endl<<"error";
        return 0;
    }
    tar=stod(check1);
    while(cin>>check1>>check2)
    {
        if(check(check1)==false||check(check2)==false)
        {
            cout<<"error"<<endl<<"error"<<endl<<"error";
            return 0;
        }
        x[i]=stod(check1);
        y[i]=stod(check2);
        i++;
    }
    int count=i;
    double x_sum=0,y_sum=0,x_avg=0,y_avg=0,lxy=0,lxx=0,lyy=0,a,b;

    for(i=0; i<count; i++)
    {
        x_sum+=x[i];
        y_sum+=y[i];
    }
    x_avg=x_sum/count;
    y_avg=y_sum/count;
    for(i=0; i<count; i++)
    {
        lxy+=(x[i]-x_avg)*(y[i]-y_avg);
        lxx+=(x[i]-x_avg)*(x[i]-x_avg);
        lyy+=(y[i]-y_avg)*(y[i]-y_avg);
    }
    b=lxy/lxx;
    a=y_avg-b*x_avg;
    if(lxx==0||lyy==0)
    {
        cout<<"error"<<endl<<"error"<<endl<<"error";
            return 0;
    }
    r=lxy/sqrt(lxx*lyy);
    output(r);
    cout<<endl;
    if(fabs(r)<0.75)
    {
        cout<<"error"<<endl<<"error";
        return 0;
    }
    cout<<"y=";
    output(b);
    cout<<"*x";
    if(a>0)
    {
        cout<<'+';
        output(a);
    }
    if(a<0)
        output(a);
    cout<<endl;
    output(b*tar+a);

    return 0;
}
