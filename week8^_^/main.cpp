#include <iostream>
#include<cstring>
using namespace std;

const char *keywords[112]= {"alignas","alignof","and","and_eq","asm","atomic_cancel","atomic_commit","atomic_noexcept","auto","bitand","bitor","bool","break","case","catch","char","char8_t","char16_t","char32_t","class","compl","concept","const","consteval","constexpr","constinit","const_cast","continue","co_await","co_return","co_yield","decltype","default","define","defined","delete","do","double","dynamic_cast","elif","else","error","endif","enum","explicit","export","extern","false","final","float","for","friend","goto","if","ifdef","ifndef","import","include","inline","int","line","long","module","mutable","namespace","new","noexcept","not","not_eq","nullptr","operator","or","or_eq","override","pragma","private","protected","public","reflexpr","register","reinterpret_cast","requires","return","short","signed","sizeof","static","static_assert","static_cast","struct","switch","synchronized","template","this","thread_local","throw","xor_eq","true","try","typedef","typeid","typename","undef","union","unsigned","using","virtual","void","volatile","wchar_t","while","xor"};
class codex
{
public:
    char *mark_words[500];
    int word_count=0;
    codex(int w=0)
    {
        for(int i=0; i<500; i++)
            mark_words[i]=new char[30];
        word_count=w;
    }
    void input()
    {
        char str[90]="";
        bool flag=true;
        int flagx=-1,tmp=0;
        char tmp_str[30]="";
        while(cin.getline(str,90))
        {
            for(int i=0; str[i]!='\0'; i++)
            {
                if(str[i]=='/'&&str[i+1]=='/')
                    break;
                if(str[i]=='/'&&str[i+1]=='*')
                {
                    flag=false;
                    i+=2;
                }
                if(str[i]=='*'&&str[i+1]=='/')
                {
                    flag=true;

                    continue;
                }
                if(str[i]=='\\'&&str[i+1]=='n')
                {
                    i+=1;
                    continue;
                }
                if(flag==false)
                    continue;
                if((str[i]=='-')&&(isok(str[i-1])==false||isok(str[i+1])==false))
                {
                    str[i]='.';
                    i--;
                    continue;
                }
                if(((str[i]=='-'||str[i]=='_')||isok(str[i]))&&str[i+1]=='\0')
                {
                    i++;
                    tmp++;
                }
                if((str[i]=='-'||str[i]=='_')||isok(str[i]))
                {
                    tmp++;
                    continue;
                }
                else
                {
                    if(tmp==0)
                        continue;
                    flagx=0;
                    strncpy(tmp_str,str+i-tmp,tmp);
                    tmp_str[tmp]='\0';
                    for(int j=0; j<word_count; j++)
                        if(strcmp(mark_words[j],tmp_str)==0)
                            flagx=1;
                    if(flagx==0)
                    {
                        strncpy(mark_words[word_count],tmp_str,30);
                        word_count++;
                    }
                    tmp=0;
                    if(str[i]=='\0') break;
                }
            }
        }
    }
    bool is_keyword(char a[30])
    {
        for(int i=0; i<112; i++)
        {
            if(strcmp(a,keywords[i])==0)
                return true;
        }
        return false;

    }
    bool isok(char a)
    {
        if((a<='Z'&&a>='A')||(a>='a'&&a<='z')||(a>='0'&&a<='9'))
            return true;
        else
            return false;

    }
    void output()
    {
        sort_words();
        int mark=word_count-1;
        for(mark=word_count-1; mark>=0; mark--)
        {
            if(is_keyword(mark_words[mark])==false)
                break;
        }
        for(int i=0; i<word_count; i++)
        {
            if(i==mark&&is_keyword(mark_words[i])==false)
            {
                cout<<mark_words[i];
                break;
            }
            if(is_keyword(mark_words[i])==false)
                cout<<mark_words[i]<<' ';
        }
    }
    void sort_words()
    {
        int max=0;
        char tmp_str[30];
        for(int i=0; i<word_count; i++)
            for(int j=i; j<word_count; j++)
            {
                if(strcmp(mark_words[i],mark_words[j])>0)
                {
                    strncpy(tmp_str,mark_words[i],30);
                    strncpy(mark_words[i],mark_words[j],30);
                    strncpy(mark_words[j],tmp_str,30);
                }
            }
    }
};
int main()
{
    codex c;
    c.input();
    c.output();
    return 0;
}
