#include <iostream>

using namespace std;

struct node
{
    char cha='\0';
    int weight=0;
    int father=-1;
    int lc=-1;
    int rc=-1;
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
    int number=0;
    int length=0;;

    void btree_get()
    {
        char ch;
        bool flag=false;
        while((ch=cin.get())!=EOF)
        {
            flag=false;
            if(ch=='\n') continue;
            if(ch<='Z'&&ch>='A') ch=ch+'a'-'A';
            for(int i=0; i<=number; i++)
                if(trees[i].cha==ch)
                {
                    trees[i].weight++;
                    flag=true;
                }
            if(flag==false)
            {

                trees[number].cha=ch;
                trees[number].weight++;
                number++;
            }
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

            for(int i=0; i<=number; i++)
            {
                if(trees[i].father==-1&&trees[i].weight<=trees[min1].weight)
                    min1=i;
            }
            for(int i=0; i<=number; i++)
                if(trees[i].father==-1&&trees[i].weight<=trees[min2].weight&&i!=min1)
                    min2=i;
            trees[min1].father=number;
            trees[min2].father=number;
            trees[number].weight=trees[min1].weight+trees[min2].weight;
            trees[number].lc=min1;
            trees[number].rc=min2;
            min1=number;
            min2=number;
            number++;
        }
        for(int i=node_num; i<number; i++)
            length+=trees[i].weight;
        for(int i=0;i<node_num;i++)
            cout<<trees[i].cha<<' '<<trees[i].weight<<endl;
    }

};

int main()
{
    htree h;
    h.btree_get();
    h.huffman();
    cout<<h.length;
    return 0;
}
