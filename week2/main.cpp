#include <iostream>
#include<iomanip>
#include <string>
using namespace std;

double cifang(double a,int b)
{
    double res=1;
    for(int i=0; i<b; i++)
        res*=a;
    return res;
}
void shuchu(double x)
{
    string temp=to_string(x);
    string::size_type pos=temp.find('.');
    string int_part,double_part;

    int_part=temp.substr(0,pos);
    double_part=temp.substr(pos+1,4);
    while(double_part.length()<4)
        double_part.append("0");
    cout<<int_part<<'.'<<double_part;
}

class duoxiangshi
{
public:
    double x;
    double num[20]= {0};
    duoxiangshi()
    {
        x=0;
    }
    duoxiangshi(const duoxiangshi& tmp)
    {
        x=tmp.x;
        for(int i=0; i<20; i++)
        {
            num[i]=tmp.num[i];
        }
    }
    double result()
    {
        double res=num[0];
        for(int i=1; i<20; i++)
            res+=cifang(x,i)*num[i];
        return res;
    }
    void qiudao()
    {
        for(int i=0; i<20; i++)
            num[i]=num[i+1]*(i+1);
        return;
    }
    void shuchul()
    {
        int flag=0;
        int flagx=0;
        for(int k=19;k>=0;k--)
        {
            if(num[k]!=0) flagx=1;
        }
        if(flagx==0)
        {
            cout<<"0.0000\n";
            return;
        }
        for(int i=19; i>=0; i--)
        {

            if(num[i]!=0)
            {
                if(flag==1&&num[i]>0)
                    cout<<'+';
                if(i==0)
                {
                    shuchu(num[0]);
                    continue;
                }
                if(i==1)
                {
                    shuchu(num[1]);
                    cout<<'x';
                    flag=1;
                    continue;
                }
                if(num[i]==1)
                {
                    if(i==1)
                    {
                        cout<<'x';
                        flag=1;
                        continue;
                    }
                    else
                    {
                        cout<<"x^"<<i;
                        flag=1;
                        continue;
                    }
                }
                shuchu(num[i]);
                cout<<"x^"<<i;
                flag=1;
            }

        }
        cout<<endl;
        return;
    }

};
int main()
{
    char *str;
    int i=0,flag=0,k=0;
    int a[20]= {0};
    double tmp;
    str=new char[100];
    cin.getline(str,100);
    duoxiangshi fa;
    cin>>fa.x;
    int flagpoint=0,xpoint=0;

    while(str[i]!='\0')
    {
        if(str[i]!='^'&&str[i]!='+'&&str[i]!='-'&&str[i]!='x'&&str[i]!='.'&&(str[i]>'9'||str[i]<'0'))
        {
            cout<<"error"<<endl<<"error"<<endl<<"error";
            return 0;
        }
        if(str[i]=='x'&&(str[i+2]>'9'||str[i+2]<'0')&&str[i+1]!='\0'&&str[i+1]!='+'&&str[i+1]!='-')
        {
            cout<<"error"<<endl<<"error"<<endl<<"error";
            return 0;
        }
        if(str[i]=='+'||(str[i]=='-'&&i!='0'))
        {
            a[k]=i;
            flagpoint=0;
            k++;
        }
        if(str[i]=='^'&&str[i+1]=='-')
        {
            cout<<"error"<<endl<<"error"<<endl<<"error";
            return 0;
        }
        if(str[i]=='.'&&flagpoint==1)
        {
            cout<<"error"<<endl<<"error"<<endl<<"error";
            return 0;
        }
        if(str[i]=='.')
            flagpoint=1;
        i++;
    }
    int last=i-1;
    int K=k;
    for(k=0; k<K; k++)
    {
        if(str[a[k]-1]=='x'&&k==0&&str[0]=='x')
        {
            fa.num[1]++;
            continue;
        }
        if(str[a[k]-1]=='x'&&k==0&&str[0]=='-'&&str[1]=='x')
        {
            fa.num[1]--;
            continue;
        }
        if(str[a[k]-1]=='x'&&k==0)
        {
            tmp=stof(str);
            fa.num[1]+=tmp;
            continue;
        }
        if(str[a[k]-2]=='^'&&k==0&&str[0]=='x')
        {
            fa.num[str[a[k]-1]-'0']++;
            continue;
        }
        if(str[a[k]-2]=='^'&&k==0&&str[0]=='-'&&str[1]=='x')
        {
            fa.num[str[a[k]-1]-'0']--;
            continue;
        }
        if(str[a[k]-2]!='^'&&k==0)
        {
            tmp=stof(str);
            fa.num[0]+=tmp;
            continue;
        }
        if(str[a[k]-1]=='x'&&k!=0)
        {
            if(str[a[k]-2]=='-')
            {
                fa.num[1]+=-1;
                continue;
            }
            if(str[a[k]-2]=='+')
            {
                fa.num[1]+=1;
                continue;
            }
            tmp=stof(str+a[k-1]);
            fa.num[1]+=tmp;
            continue;
        }
        if(str[a[k]-2]!='^')
        {
            tmp=stof(str+a[k-1]);
            fa.num[0]+=tmp;
            continue;
        }
        if(str[a[k]-2]=='^'&&str[a[k]-4]=='-')
        {
            fa.num[str[a[k]-1]-'0']--;
            continue;
        }
        if(str[a[k]-2]=='^'&&str[a[k]-4]=='+')
        {
            fa.num[str[a[k]-1]-'0']++;
            continue;
        }
        tmp=stof(str+a[k-1]);
        fa.num[str[a[k]-1]-'0']+=tmp;

    }
    if(str[last]=='x'&&str[last-1]=='+')
        tmp=1;
    else if(str[last]=='x'&&str[last-1]=='-')
        tmp=-1;
    else
        tmp=stof(str+a[k-1]);
    if(str[last]=='x')
        fa.num[1]+=tmp;
    if(str[last-1]=='^')
        fa.num[str[last]-'0']+=tmp;
    if(str[last-1]!='^'&&str[last]!='x')
        fa.num[0]+=tmp;
    fa.shuchul();
    double tar=fa.result();
    fa.qiudao();
    fa.shuchul();
    shuchu(tar);

    return 0;

}
