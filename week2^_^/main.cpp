#include <iostream>
#include<iomanip>
#include<cstring>
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
    double num[11]= {0};
    int maxnum;
    duoxiangshi()
    {
        x=0;
    }
    duoxiangshi(const duoxiangshi& tmp)
    {
        x=tmp.x;
        for(int i=0; i<10; i++)
        {
            num[i]=tmp.num[i];
        }
    }
    void intput()
    {
        char *str,*tmp;
        int a[50]= {0},k=0,K,i,length;
        double fans=0;
        str=new char[100];
        tmp=new char[100];
        cin.getline(str,100);
        if(str[0]=='0'&&str[1]=='\0')
        {
            return;
        }
        for(i=0; str[i]!='\0'; i++)
            if((str[i]=='+'||str[i]=='-')&&i!=0)
            {
                a[k]=i;
                k++;
            }

        if(k==0)
        {
            strncpy(tmp,str,strlen(str));
            length=strlen(str);
            if(tmp[0]=='x'&&length==1)//x
            {
                num[1]++;
                return;
            }
            if(tmp[0]=='x'&&length==3)//x^n
            {
                num[tmp[length-1]-'0']++;
                return;
            }
            if(tmp[length-1]=='x'&&tmp[0]=='+'&&length==2)//+x
            {
                num[1]++;
                return;
            }
            if(tmp[length-1]=='x'&&tmp[0]=='-'&&length==2)//-x
            {
                num[1]--;
                return;
            }
            if(tmp[length-2]=='^'&&tmp[0]=='+'&&length==4)//+x^n
            {
                num[tmp[length-1]-'0']++;
                return;
            }
            if(tmp[length-2]=='^'&&tmp[0]=='+'&&length==4)//-x^n
            {
                num[tmp[length-1]-'0']--;
                return;
            }
            if(tmp[length-1]=='x')//+-mx
            {
                fans=stof(tmp);
                num[1]+=fans;
                return;
            }
            if(tmp[length-2]=='^')//+-mx^n
            {
                fans=stof(tmp);
                num[tmp[length-1]-'0']+=fans;
                return;
            }
            if(tmp[length-2]!='^'&&tmp[length-1]!='x')//常数
            {
                fans=stof(tmp);
                num[0]+=fans;

                return;
            }
        }
        K=k;
        strncpy(tmp,str,a[0]);
        length=a[0];
        for(int j=0; j<=k; j++)
        {
            if(j!=0)
            {
                if(j==k)
                {
                    strncpy(tmp,str+a[j-1],strlen(str)-a[j-1]);
                    length=strlen(str)-a[j-1];
                }
                else
                {
                    strncpy(tmp,str+a[j-1],a[j]-a[j-1]);
                    length=a[j]-a[j-1];
                }
            }

            if(tmp[0]=='x'&&length==1)//x
            {
                num[1]++;
                continue;
            }
            if(tmp[0]=='x'&&length==3)//x^n
            {
                num[tmp[length-1]-'0']++;
                continue;
            }
            if(tmp[length-1]=='x'&&tmp[0]=='+'&&length==2)//+x
            {
                num[1]++;
                continue;
            }
            if(tmp[length-1]=='x'&&tmp[0]=='-'&&length==2)//-x
            {
                num[1]--;
                continue;
            }
            if(tmp[length-2]=='^'&&tmp[0]=='+'&&length==4)//+x^n
            {
                num[tmp[length-1]-'0']++;
                continue;
            }
            if(tmp[length-2]=='^'&&tmp[0]=='-'&&length==4)//-x^n
            {
                num[tmp[length-1]-'0']--;
                continue;
            }
            if(tmp[length-1]=='x')//+-mx
            {
                fans=stof(tmp);
                num[1]+=fans;
                continue;
            }
            if(tmp[length-2]=='^')//+-mx^n
            {
                fans=stof(tmp);
                num[tmp[length-1]-'0']+=fans;
                continue;
            }
            if(tmp[length-2]!='^'&&tmp[length-1]!='x')//常数
            {
                fans=stof(tmp);
                num[0]+=fans;

                continue;
            }


        }
        return;
    }
    double result()
    {
        double res=num[0];
        for(int i=1; i<10; i++)
            res+=cifang(x,i)*num[i];
        return res;
    }
    void qiudao()
    {
        for(int i=0; i<10; i++)
            num[i]=num[i+1]*(i+1);
        return;
    }
    int findmaxnum()
    {
        for(int i=10; i>=0; i--)
            if(num[i]!=0)
                return i;
    }
    void shuchul()
    {
        int flag=0;
        int flagx=0;
        for(int k=10; k>=0; k--)
        {
            int x=int(num[k]*10000);
            double qwe;
            qwe=x/10000.0;
            if(qwe!=0)
                flagx=1;
        }
        if(flagx==0)
        {
            cout<<"0.0000";
            return;
        }
        for(int i=10; i>=0; i--)
        {
            int x=int(num[i]*10000);
            double qwe;
            qwe=x/10000.0;
            if(qwe!=0)
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
        return;
    }

};

int main()
{
    duoxiangshi p;
    duoxiangshi q;
    duoxiangshi res;
    p.intput();
    q.intput();
    int m=p.findmaxnum();
    int n=q.findmaxnum();
    int flagx=0;
    for(int k=10; k>=0; k--)
    {
        if(q.num[k]!=0)
            flagx=1;
    }
    if(flagx==0)
    {
        cout<<"error"<<endl<<"error";
        return 0;
    }
    for(int i=m-n; i>=0; i--)
    {
        res.num[i]=p.num[i+n]/q.num[n];
        for(int j=n; j>=0; j--)
        {
            p.num[i+j]=p.num[i+j]-q.num[j]*res.num[i];
        }
    }
    res.shuchul();
    cout<<endl;
    p.shuchul();
    return 0;

}
