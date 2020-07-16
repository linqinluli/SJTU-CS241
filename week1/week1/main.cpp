#include <iostream>
#include <vector>

using namespace std;

class number
{
public:
    int point=-1;
    int zhengfu=1;
    int weishu=-1;
    double ans;
    vector <int> a;
    number()
    {
        point=-1;
        zhengfu=1;
        weishu=0;
    }
    number(const number &x)
    {
        point=x.point;
        zhengfu=x.zhengfu;
        weishu=x.weishu;
        a.insert(a.end(),x.a.begin(),x.a.end());
    }
    number& operator =(number tmp)
    {
        point=tmp.point;
        zhengfu=tmp.zhengfu;
        weishu=tmp.weishu;
        a.clear();
        a.insert(a.end(),tmp.a.begin(),tmp.a.end());
    }
    void show_number()//输出函数
    {
        if(zhengfu==3)
        {
            cout<<"error";
            return;
        }
        return;
        if(zhengfu==-1)
            cout<<'-';
        for(int i=0; i<=weishu; i++)
        {
            if(i==point)
                cout<<'.';
            cout<<a[i];
        }
        return;
    }
};

class expression
{
public:
    number one;
    number two;
    char fuhao;
    expression()
    {
        fuhao='=';
    }
    number calculation()//计算
    {
        number x,result;
        x.weishu=0;
        int special=0;
        x.a.push_back(0);
        double x1,x2;
        if(bijiao(one,two)==-1)
            special=1;
        if(one.point)
            if(fuhao=='+')
            {
                double a=trans(one);
                double b=trans(two);

                result.ans=a+b;
                cout<<result.ans;
                return result;
            }
        if(fuhao=='-')
        {
            double a=trans(one);
            double b=trans(two);

            if(special==1)
            {
                cout<<0;
                return result;
            }
            result.ans=a-b;
            cout<<result.ans;
            return result;
        }
        if(fuhao=='*')
        {
            if(one.weishu==two.weishu&&one.weishu==127)
            {
                cout<<"error";
                return result;
            }
            double a=trans(one);
            double b=trans(two);

            result.ans=a*b;
            cout<<result.ans;
            return result;
        }
        if(fuhao=='/')
        {
            if(special==1)
            {
                cout<<1;
                return result;
            }
            if(two.weishu==0&&two.a[0]==0)
            {
                result.zhengfu=3;
                return result;
            }
            if(one.point!=-1||two.point!=-1)
            {
                result.zhengfu=3;
                return result;
            }
            double a=trans(one);
            double b=trans(two);

            result.ans=a/b;
            cout<<result.ans;
            return result;
        }

    }

    double trans(number x)//转化成double
    {
        double res=0,tmp=0,xiaoshu=0.1;
        for(int i=0; i<=x.weishu; i++)
        {
            for(int j=0; j<=x.weishu-i; j++)
            {
                if(j==0)
                    tmp=x.a[i];
                tmp=tmp*10;
            }
            res+=tmp;
        }
        for(int i=0; i<=x.weishu-x.point; i++)
            xiaoshu*=0.1;
        if(x.zhengfu==-1)
            res= -res;
        if(x.point==-1)
            return res/10.0;
        else
            return res*xiaoshu;
    }
    int bijiao(number a,number b)//判断两数大小
    {
        if(a.zhengfu==1&&b.zhengfu==-1)
            return true;
        if(a.zhengfu==-1&&b.zhengfu==1)
            return false;
        if(a.weishu>b.weishu)
            return true;
        if(a.weishu<b.weishu)
            return false;
        if(a.weishu==b.weishu)
        {
            for(int i=0; i<=a.weishu; i++)
            {
                if(a.a[i]>b.a[i])
                    return true;
                if(a.a[i]<b.a[i])
                    return false;
            }
            return -1;
        }
    }


};
int main()
{
    expression x;
    char input[300];
    cin.getline(input,300);
    int i=0,weishu1=0,weishu2=0;
    int which_number=0;
    if(input[0]=='-')
    {
        x.one.zhengfu=-1;
        i++;
    }
    while(input[i]!='\0')
    {
        if(input[i]=='-'&&input[i-1]!='<')
        {
            x.two.zhengfu=-1;
            i++;
        }
        if(input[i]=='.'&&which_number==0)
        {
            x.one.point=weishu1;
            weishu1++;
            i++;
            continue;
        }
        if(input[i]=='.'&&which_number==1)
        {
            x.two.point=weishu2;
            weishu2++;
            i++;
            continue;
        }
        if(input[i]=='<')
        {
            if(input[i+3]=='?')
            {
                cout<<"error";
                return 0;
            }
            if(input[i+2]!='>')
            {
                cout<<"error";
                return 0;
            }
            else
            {
                if(input[i+1]=='+')
                    x.fuhao='+';
                if(input[i+1]=='-')
                    x.fuhao='-';
                if(input[i+1]=='*')
                    x.fuhao='*';
                if(input[i+1]=='/')
                    x.fuhao='/';
            }
            which_number=1;
            i+=3;
            continue;
        }
        if(which_number==0)
        {
            x.one.a.push_back(input[i]-'0');
            weishu1++;
        }
        else
        {
            x.two.a.push_back(input[i]-'0');
            weishu2++;
        }
        i++;
    }
    if(weishu1>128||weishu2>128)
    {
        cout<<"error";
        return 0;
    }
    x.one.weishu=weishu1-1;
    x.two.weishu=weishu2-1;

    x.calculation().show_number();
    return 0;
}
