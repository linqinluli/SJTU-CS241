#include <iostream>
#include<cstring>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;
void output(double x)
{
    if(x<0&&x>-0.0001)
    {
        cout<<"-0.0000";
        return;
    }
	if(x==-0)
	{cout<<"0.0000";
	return;}
    cout<<fixed<<setprecision(4);
    int temp=int(x*10000);
    cout<< double(temp)/10000;
}
void forward_one(double num[100],int i)
{
    for(; i<99; i++)
    {
        num[i]=num[i+1];
        num[i+1]=0;
    }
    return;
}
bool check_zero(double num[100],int i)
{
    for(i++; i<=99; i++)
        if(num[i]!=0)
            return false;
    return true;
}
void swap_row(double one[],double two[])
{
    double tmp;
    for(int i=0; i<100; i++)
    {
        tmp=one[i];
        one[i]=two[i];
        two[i]=tmp;
    }
    return;
}
class Map
{
public:
    double A[100][100]= {{0}};
    double b[100]= {0};
    double x[100]= {0};
    bool isright=true;
    int N=0;
    int find_max(double tar[100])
    {
        for(int i=99; i>=0; i--)
        {
            if(tar[i]!=0)
                return i;
        }
    }
    void inputall()
    {
        char *str,*left,*right;
        int i=0,row=0,position=0;
        str=new char[100];
        left=new char[100];
        right=new char[100];
        while(cin.getline(str,100))
        {
            for(i=0; i<strlen(str); i++)
            {
                if(str[i]=='=')
                    position=i;
                if(str[i]=='?')
                {
                    isright=false;
                    return;
                }
            }
            strncpy(left,str,position);
            left[position]='\0';
            strncpy(right,str+position+1,i-position);
            right[i-position]='\0';
            intputline_left(A[row],left);
            intputline_right(A[row],right);
            b[row]=-A[row][0];
            row++;
        }
        N=row;
        bool isok=false;
        int maxone=find_max(A[0]);
        for(int m=1; m<=maxone; m++)
        {
            isok=false;
            for(int n=0; n<N; n++)
            {
                if(A[n][m]!=0)
                    isok=true;
            }
            if(isok==false)
            {
                for(int rtk=0; rtk<N; rtk++)
                    forward_one(A[rtk],m);
                m--;
            }
            int flag=true;
            for(int n=0; n<N; n++)
                if(check_zero(A[n],m)==false)
                    flag=false;
            if(flag==true)
                break;
        }
        for(int j=0; j<row; j++)
        {
            if(find_max(A[j])>N)
                isright=false;
            b[j]=-A[j][0];
        }
        return;
    }
    void intputline_left(double num[100],char *str)
    {
        char *tmp;
        int a[50]= {0},k=0,i,length;
        double fans=0;
        int cues=0;
        tmp=new char[100];
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
            if(tmp[0]=='x'&&length==4)//x_n
            {
                num[stoi(tmp+2)]++;
                return;
            }
            if(tmp[0]=='x'&&length==3)//x_n
            {
                num[tmp[length-1]-'0']++;
                return;
            }
            if(tmp[length-3]=='_')//+-mx^n
            {
                fans=stod(tmp);
                cues=stoi(tmp+4);
                num[cues]+=fans;
                return;
            }
            if(tmp[length-2]=='_')//+-mx^n
            {
                fans=stod(tmp);
                num[tmp[length-1]-'0']+=fans;
                return;
            }
            if(tmp[length-2]!='_'&&tmp[length-1]!='x')//常数
            {
                fans=stod(tmp);
                num[0]+=fans;
                return;
            }
        }
        strncpy(tmp,str,a[0]);
        length=a[0];
        for(int j=0; j<=k; j++)
        {
            if(j!=0)
            {
                if(j==k)
                {
                    strncpy(tmp,str+a[j-1],strlen(str)-a[j-1]);
                    tmp[strlen(str)-a[j-1]]='\0';
                    length=strlen(str)-a[j-1];
                }
                else
                {
                    strncpy(tmp,str+a[j-1],a[j]-a[j-1]);
                    tmp[a[j]-a[j-1]]='\0';
                    length=a[j]-a[j-1];
                }
            }

            if(tmp[0]=='x'&&length==3)//x^n
            {
                num[tmp[length-1]-'0']++;
                continue;
            }
            if(tmp[0]=='x'&&length==4)//x_nn
            {
                cues=stoi(tmp+2);
                num[cues]++;
                continue;
            }
            if(tmp[length-2]=='_'&&tmp[0]=='+'&&length==4)//+x^n
            {
                num[tmp[length-1]-'0']++;
                continue;
            }
            if(tmp[length-3]=='_'&&tmp[0]=='+'&&length==5)//+x^nn
            {
                cues=stoi(tmp+3);
                num[cues]++;
                continue;
            }
            if(tmp[length-2]=='_'&&tmp[0]=='-'&&length==4)//-x^n
            {
                num[tmp[length-1]-'0']--;
                continue;
            }
            if(tmp[length-3]=='_'&&tmp[0]=='-'&&length==5)//-x^nn
            {
                cues=stoi(tmp+3);
                num[cues]--;
                continue;
            }

            if(tmp[length-3]=='_')//+-mx^n
            {
                fans=stod(tmp);
                cues=stoi(tmp+length-2);
                num[cues]+=fans;
                continue;
            }
            if(tmp[length-2]=='_')//+-mx^n
            {
                fans=stod(tmp);
                cues=stoi(tmp+length-1);
                num[cues]+=fans;
                continue;
            }
            if(tmp[length-2]!='_'&&tmp[length-1]!='x')//常数
            {
                fans=stod(tmp);
                num[0]+=fans;
                continue;
            }
        }
        return;
    }
    void intputline_right(double num[100],char *str)
    {
        char *tmp;
        int a[50]= {0},k=0,i,length;
        double fans=0;
        int cues=0;
        tmp=new char[100];
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
            if(tmp[0]=='x'&&length==4)//x_n
            {
                num[stoi(tmp+2)]--;
                return;
            }
            if(tmp[0]=='x'&&length==3)//x_n
            {
                num[tmp[length-1]-'0']--;
                return;
            }
            if(tmp[length-3]=='_')//+-mx^n
            {
                fans=stod(tmp);
                cues=stoi(tmp+4);
                num[cues]-=fans;
                return;
            }
            if(tmp[length-2]=='_')//+-mx^n
            {
                fans=stod(tmp);
                num[tmp[length-1]-'0']-=fans;
                return;
            }
            if(tmp[length-2]!='_'&&tmp[length-1]!='x')//常数
            {
                fans=stod(tmp);
                num[0]-=fans;
                return;
            }
        }
        strncpy(tmp,str,a[0]);
        length=a[0];
        for(int j=0; j<=k; j++)
        {
            if(j!=0)
            {
                if(j==k)
                {
                    strncpy(tmp,str+a[j-1],strlen(str)-a[j-1]);
                    tmp[strlen(str)-a[j-1]]='\0';
                    length=strlen(str)-a[j-1];
                }
                else
                {
                    strncpy(tmp,str+a[j-1],a[j]-a[j-1]);
                    tmp[a[j]-a[j-1]]='\0';
                    length=a[j]-a[j-1];
                }
            }

            if(tmp[0]=='x'&&length==3)//x^n
            {
                num[tmp[length-1]-'0']--;
                continue;
            }
            if(tmp[0]=='x'&&length==4)//x_nn
            {
                cues=stoi(tmp+2);
                num[cues]--;
                continue;
            }
            if(tmp[length-2]=='_'&&tmp[0]=='+'&&length==4)//+x^n
            {
                num[tmp[length-1]-'0']--;
                continue;
            }
            if(tmp[length-3]=='_'&&tmp[0]=='+'&&length==5)//+x^nn
            {
                cues=stoi(tmp+3);
                num[cues]--;
                continue;
            }
            if(tmp[length-2]=='_'&&tmp[0]=='-'&&length==4)//-x^n
            {
                num[tmp[length-1]-'0']++;
                continue;
            }
            if(tmp[length-3]=='_'&&tmp[0]=='-'&&length==5)//-x^nn
            {
                cues=stoi(tmp+3);
                num[cues]++;
                continue;
            }

            if(tmp[length-3]=='_')//+-mx^n
            {
                fans=stod(tmp);
                cues=stoi(tmp+length-2);
                num[cues]-=fans;
                continue;
            }
            if(tmp[length-2]=='_')//+-mx^n
            {
                fans=stod(tmp);
                cues=stoi(tmp+length-1);
                num[cues]-=fans;
                continue;
            }
            if(tmp[length-2]!='_'&&tmp[length-1]!='x')//常数
            {
                fans=stod(tmp);
                num[0]-=fans;
                continue;
            }
        }
        return;
    }
    void find_result()
    {
        if(isright==false)
        {
            cout<<"error";
            return;
        }//输出阶段判断是否错误

        int k=0,i=0,j=0;
        double tmp=0,tmpb=0;
        for(k=0; k<N; k++)
        {
            if(A[k][k+1]==0)//寻找主元
            {
                for(int m=k+1; m<N; m++)
                    if(A[m][m+1]!=0)
                    {
                        swap_row(A[k],A[m]);
                        tmpb=b[k];
                        b[k]=b[m];
                        b[m]=tmpb;
                        break;
                    }
            }
            if(A[k][k+1]==0)//主元未找到判断为错误
            {
                isright=false;
            }
            if(isright==false)//输出错误
            {
                cout<<"error";
                return;
            }
            for(i=k+1; i<N; i++)//变成上三角
            {
                tmp=A[i][k+1]/A[k][k+1];
                for(j=k+1; j<=N; j++)
                {
                    A[i][j]=A[i][j]-tmp*A[k][j];
                }
                b[i]=b[i]-tmp*b[k];
            }
        }
        x[N-1]=b[N-1]/A[N-1][N];
        for(k=N-2; k>=0; k--)//带入求解
        {
            double s=b[k];
            for(j=k+1; j<N; j++)
            {
                s=s-A[k][j+1]*x[j];
            }
            x[k]=s/A[k][k+1];
        }

        for(i=0; i<N-1; i++)
        {
            output(x[i]);
            cout<<' ';
        }
        output(x[N-1]);
        return;
    }
};
int main()
{
    Map X;
    X.inputall();
    X.find_result();
    return 0;
}
