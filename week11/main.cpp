#include <iostream>

using namespace std;

void sortint(int people[],int num)
{
    int tmp=0;
    for(int i=0; i<num; i++)
        for(int j=i; j<num; j++)
            if(people[i]<people[j])
            {
                tmp=people[i];
                people[i]=people[j];
                people[j]=tmp;
            }
    return;

}
int main()
{
    int w=0,n=0;
    int flag=0;
    cin>>w>>n;
    int people[10000]= {0};
    int isget[10000]= {0};
    for(int i=0; i<n; i++)
    {
        cin>>people[i];
        if(people[i]<=0)
        {
            flag=1;
            break;
        }
        if(people[i]>w)
            flag=2;
    }
    if(flag==2)
    {
        cout<<"out";
        return 0;
    }
    if(flag==1)
    {
        cout<<"error";
        return 0;
    }
    sortint(people,n);
    int tmpship=0,ship_num=0,tmppeople=0;
    while(true)
    {
        bool flagx=false;
        for(int i=0; i<n; i++)
            if(isget[i]==0)
                flagx=true;
        if(flagx==false)
        {
            if(tmppeople!=0)
ship_num++;
                break;
        }
        bool isup=false;
        for(int i=0; i<n; i++)
        {
            if(people[i]<=w-tmpship&&isget[i]!=1)
            {
                tmpship+=people[i];
                isget[i]=1;
                isup=true;
                tmppeople++;
            }
            if(tmppeople==2)
                break;
        }
        if(isup==false||tmppeople==2)
        {
            ship_num++;
            tmpship=0;
            tmppeople=0;
        }
    }
    cout<<ship_num;


    return 0;
}
