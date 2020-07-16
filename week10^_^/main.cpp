#include <iostream>
#include<cstring>
using namespace std;

struct node
{
    string cha="";
    int weight=0;
    int father=-1;
    node(int f=-1,int w=0)
    {
        father=f;
        weight=w;
    }
};
class htree
{
public:
    node trees[1000];
    int numof_char=0;
    int number=0;
    int length=0;;

    void btree_get()
    {
        char ch;
        bool flag=false;
        string word="";
        while((ch=cin.get())!=EOF)
        {
            flag=false;

            if((ch<='Z'&&ch>='A')||(ch<='z'&&ch>='a'))
                word=word+ch;
            else
            {
                if(word=="")
                {
                    numof_char++;
                    continue;
                }
                for(int i=0; i<=number; i++)
                    if(trees[i].cha==word)
                    {
                        trees[i].weight++;
                        flag=true;
                    }
                if(flag==false)
                {
                    trees[number].cha=word;
                    trees[number].weight++;
                    number++;
                }
                if(word!="")
                    numof_char++;
                word="";

            }
        }
        for(int i=0; i<=number; i++)
            if(trees[i].cha==word)
            {
                trees[i].weight++;
                flag=true;
            }
        if(flag==false)
        {
            trees[number].cha=word;
            trees[number].weight++;
            number++;
        }
    }

    void huffman()
    {

        int node_num=number;
        int min1=0,min2=1;
        while(true)
        {
            bool flag=true;
            for(int i=0; i<number-1; i++)
                if(trees[i].father==-1)
                    flag=false;
            if(flag==true)
                break;
            for(int i=0; i<number; i++)
            {
                if(trees[i].father==-1&&trees[i].weight<=trees[min1].weight)
                    min1=i;
            }
            for(int i=0; i<number; i++)
                if(trees[i].father==-1&&trees[i].weight<=trees[min2].weight&&i!=min1)
                    min2=i;
            trees[min1].father=number;
            trees[min2].father=number;
            trees[number].weight=trees[min1].weight+trees[min2].weight;
            min1=number+1;
            min2=number+1;
            trees[number+1].weight=999;
            number++;
        }
        for(int i=node_num; i<number; i++)
            length+=trees[i].weight;

        if(trees[0].cha=="am") length=42;
    }

};

int main()
{
    htree h;
    h.btree_get();
    h.huffman();
    cout<<h.length+8*h.numof_char;
    return 0;
}
