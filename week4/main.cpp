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
struct fx
{
    double x=0;
    double y=0;
    fx(double a=0,double b=0)
    {
        x=a;
        y=b;
    }
};
void swap_fx(fx &a,fx &b)
{
    double tmpx,tmpy;
    tmpx=a.x;
    tmpy=a.y;
    a.x=b.x;
    a.y=b.y;
    b.x=tmpx;
    b.y=tmpy;
}
void sortfx(fx A[100],int m)
{
    for(int i=0; i<=m; i++)
        for(int j=i; j<=m; j++)
            if(A[j].x<A[i].x)
                swap_fx(A[i],A[j]);
}
double cr(double t,double k)
{
    double res=1;
    for(int i=0; i<=k; i++)
        res*=(t-i);
    return res;
}
double jiecheng(int k)
{
    int res=1;
    for(int i=k; i>0; i--)
        res*=i;
    return res;
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
    fx mar[100];
    char* check1,*check2;
    check1=new char[10];
    check2=new char[10];
    double tar,a,t;
    int i=0,Max,N;
    cin.getline(check1,10);
    if(check(check1)==false)
    {
        cout<<"error";
        return 0;
    }
    tar=stod(check1);
    while(cin>>check1>>check2)
    {
        if(check(check1)==false||check(check2)==false)
        {
            cout<<"error";
            return 0;
        }
        mar[i].x=stod(check1);
        mar[i].y=stod(check2);
        i++;
    }
    Max=i-1;
    N=Max;
    sortfx(mar,Max);
    double h=mar[1].x-mar[0].x;
    for(i=1; i<=Max; i++)
        if(abs(h-mar[i].x+mar[i-1].x)>0.0000001)
        {
            cout<<"error";
            return 0;
        }
    t=(tar-mar[0].x)/h;
    a=mar[0].x;
    double d[100][100]= {{0}};
    for(i=0; i<Max; i++)
        d[0][i]=mar[i+1].y-mar[i].y;
    for(i=1; i<Max; i++)
        for(int j=0; j<Max; j++)
            d[i][j]=d[i-1][j+1]-d[i-1][j];
    double tmp_res=1,result=mar[0].y;
    for(i=1; i<=N; i++)
    {
        tmp_res=d[i-1][0]/jiecheng(i)*cr(t,i-1);
        result+=tmp_res;
    }
    output(result);
    return 0;
}
