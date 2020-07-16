#include<iostream>
#include<vector>

using namespace std;

string strc[1000][1000];
int longestPalindromeSubseq(string s)
{
    int n=s.length();
    vector<vector<int>> tmp(n,vector<int>(n));
    for(int i=0; i<n; i++)
    {
        tmp[i][i]=0;
        strc[i][i]="";
        for(int j=i-1; j>=0; j--)
        {

            if(s[j]==s[i])
            {
                strc[j][i]=s[i]+strc[j+1][i-1]+s[j];
                tmp[j][i]=tmp[j+1][i-1]+2;
            }
            else
            {
                tmp[j][i]=max(tmp[j+1][i],tmp[j][i-1]);
                if(tmp[j+1][i]>=tmp[j][i-1])
                    strc[j][i]=strc[j+1][i];
                else
                    strc[j][i]=strc[j][i-1];
            }
        }
    }
    return tmp[0][n-1];
}
int main()
{
    char str[1000];
    cin.getline(str,1000);
    int length=longestPalindromeSubseq(str),i=0;
    int n=0;
    for(n=0; str[n]!='\0'; n++);
    cout<<strc[0][n-1];
    return 0;
}
