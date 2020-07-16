#include <iostream>
#include<cstring>
#include<vector>
using namespace std;

struct word
{
    char str[300]="";
    int length=0;
    int frquency=0;
    word(const char strl[300]="",int frquencyl=0)
    {
        strcpy(str,strl);
        frquency=frquencyl;
    }
};
class words
{

public:
    word w[300];
    word tarw[300];
    int tarwords=0;
    int word_count=0;
    int all_word=0;
    word maxones[5];
    void get_words()
    {
        int i=0,tmp=0,m=0;
        char novel[100000];
        char tar_sentence[10000];
        char tmp_str[3000];
        int flag=0;
        cin.getline(novel,100000);
        while(novel[i]!='\0')
        {
            if((novel[i]=='-'||novel[i]=='_')&&(isok(novel[i-1])==false||isok(novel[i+1])==false))
            {
                novel[i]='.';
                continue;
            }
            if(((novel[i]=='-'||novel[i]=='_')||isok(novel[i]))&&novel[i+1]=='\0')
            {
                i++;
                tmp++;
            }
            if((novel[i]=='-'||novel[i]=='_')||isok(novel[i]))
            {
                i++;
                tmp++;
                continue;
            }
            else
            {
                if(tmp==0)
                {
                    i++;
                    continue;
                }
                all_word++;
                flag=0;
                strncpy(tmp_str,novel+i-tmp,tmp);
                tmp_str[tmp]='\0';

                i++;
                for(int j=0; j<word_count; j++)
                {
                    if(same(w[j].str,tmp_str)==0)
                    {
                        w[j].frquency++;
                        flag=1;
                    }
                    if(same(w[j].str,tmp_str)==1)
                    {
                        w[j].frquency++;
                    }
                }
                if(flag==0)
                {
                    strncpy(w[word_count].str,tmp_str,tmp);
                    w[word_count].frquency++;
                    for(int qq=0; qq<word_count; qq++)
                    {
                        if(same(w[qq].str,w[word_count].str)==1)
                        {
                            w[word_count].frquency=w[qq].frquency;
                        }
                    }
                    word_count++;
                }
                tmp=0;
            }
        }
        cin.getline(tar_sentence,10000);
        i=0;
        tmp=0;
        while(tar_sentence[i]!='\0')
        {
            if((tar_sentence[i]=='-'||tar_sentence[i]=='_')&&(isok(tar_sentence[i-1])==false||isok(tar_sentence[i+1])==false))
            {
                tar_sentence[i]=',';
                continue;
            }
            if(((tar_sentence[i]=='-'||tar_sentence[i]=='_')||isok(tar_sentence[i]))&&tar_sentence[i+1]=='\0')
            {
                i++;
                tmp++;
            }
            if(isok(tar_sentence[i])||(tar_sentence[i]=='-'||tar_sentence[i]=='_'))
            {
                i++;
                tmp++;
                continue;
            }
            else
            {
                if(tmp==0)
                {
                    i++;
                    continue;
                }
                flag=0;
                strncpy(tmp_str,tar_sentence+i-tmp,tmp);
                tmp_str[tmp]='\0';
                i++;
                strncpy(tarw[m].str,tmp_str,tmp);
                m++;
                tmp=0;
            }
        }
        strncpy(tarw[m].str,tar_sentence+i-tmp,tmp);
        tarwords=m;
    }
    bool isok(char a)
    {
        if((a<='Z'&&a>='A')||(a>='a'&&a<='z')||(a>='0'&&a<='9'))
            return true;
        else
            return false;
    }
    int same(char a[300],char b[300])
    {
        int checka=-1,checkb=-2,type=0,i=0;
        while(a[i]!='\0'&&b[i]!='\0')
        {
            if(a[i]==b[i])
            {
                i++;
                continue;
            }
            if((a[i]<='z'&&a[i]>='a'))
                checka=a[i]-'a';
            if((a[i]<='Z'&&a[i]>='A'))
                checka=a[i]-'A';
            if((b[i]<='z'&&b[i]>='a'))
                checkb=b[i]-'a';
            if((b[i]<='Z'&&b[i]>='A'))
                checkb=b[i]-'A';
            if(checka!=checkb&&b[i]!=a[i])
            {
                return -1;
            }
            if(b[i]!=a[i])
                type=1;
            i++;
            checka=1;
            checkb=0;
        }
        if((a[i]=='\0'&&b[i]!='\0')||(a[i]!='\0'&&b[i]=='\0'))
            return -1;
        return type;
    }

    void find_maxs()
    {
        int max=0,num=word_count;
        char max_str[3000]="";
        for(int m=0; m<word_count; m++)
            for(int n=m+1; n<word_count-1; n++)
            {
                if(same(w[m].str,w[n].str)!=-1&&strcmp(w[m].str,w[n].str)>0)
                    w[n].frquency=0;
                if(same(w[m].str,w[n].str)!=-1&&strcmp(w[m].str,w[n].str)<0)
                    w[m].frquency=0;
            }
        if(word_count>=6)
            num=5;
        for(int j=0; j<num; j++)
        {

            for(int i=0; i<word_count; i++)
            {
                if(w[i].frquency>w[max].frquency)
                {
                    max=i;
                }
                if(w[i].frquency==w[max].frquency)
                {
                    if(same(w[i].str,w[max].str)==1&&strcmp(w[i].str,w[max].str)>0)
                    {
                        max=i;
                        continue;
                    }
                    if(same(w[i].str,w[max].str)!=1&&strcmp(w[i].str,w[max].str)<0)
                    {
                        max=i;
                        continue;
                    }

                }
            }
            maxones[j].frquency=w[max].frquency;
            strcpy(maxones[j].str,w[max].str);
            for(int ii=00; ii<word_count; ii++)
            {
                if(same(w[ii].str,w[max].str)!=-1)
                {
                    w[max].frquency=0;
                    w[ii].frquency=0;
                }
            }
        }
        for(int i=0; i<num; i++)
        {
            if(maxones[i].frquency==0)
                break;
            if(i==num-1)
            {
                cout<<'('<<maxones[i].str<<','<<maxones[i].frquency<<')';
                break;
            }
            cout<<'('<<maxones[i].str<<','<<maxones[i].frquency<<") ";
        }
        cout<<endl;
    }
    void find_tars()
    {
        for(int i=0; i<tarwords; i++)
            for(int j=0; j<word_count; j++)
            {
                if(same(tarw[i].str,w[j].str)!=-1)
                    tarw[i].frquency=w[j].frquency;
            }
    }
    void outputtarw()
    {
        for(int i=0; i<tarwords; i++)
        {
            if(i==tarwords-1)
                cout<<'('<<tarw[i].str<<','<<tarw[i].frquency<<')';
            else
                cout<<'('<<tarw[i].str<<','<<tarw[i].frquency<<") ";
        }
    }
};

int main()
{
    words chick;
    chick.get_words();
    cout<<chick.all_word<<endl;
    chick.find_tars();
    chick.find_maxs();
    chick.outputtarw();
    return 0;
}

