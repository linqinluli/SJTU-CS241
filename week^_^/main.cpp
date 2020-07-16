#include <iostream>

using namespace std;

int m[100000]= {0};

int f(int i)
{
    if(i==0)
        return m[0];
    else
        return max(f(i-1)+m[i],m[i]);
}
int main()
{
    int n,i=0;
    cin>>n;
    while(cin>>m[i])
    {
        if(m[i]>1000||m[i]<-1000)
        {
            cout<<"error";
            return 0;
        }
        i++;
    }
    if(i!=n)
    {
        cout<<"error";
        return 0;
    }
    int maxn=-99,maxi=0,maxj=0;
    for(int i=0; i<n; i++)
        if(maxn<f(i))
        {
            maxn=f(i);
            maxi=i;
        }
    int sum=0;
    for(int i=0; i<=maxi; i++)
    {
        for(int j=i; j<=maxi; j++)
            sum+=m[j];
        if(sum==maxn) {maxj=i;break;}
        sum=0;
    }
    cout<<maxn<<' '<<maxj+1<<' '<<maxi+1;
    return 0;
}
