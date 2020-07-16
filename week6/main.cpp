#include <iostream>
#include<cstring>
#include<string>
using namespace std;
struct node
{
    bool isget=false;
    bool is_graph=false;
    bool ishead=false;
    bool isbtree=true;
    int num=-1;
    int father[100];
    int child[100];
    int child_num=0;
    int father_num=0;
    node()
    {
        for(int i=0; i<10; i++)
        {
            father[i]=-1;
            child[i]=-1;
        }
    }
};
struct r
{
    int res=0;
    int size=0;
};
node data[10000];
r res_of_graph[1000];
r res_of_tree[1000];
r res_of_binarytree[1000];
r res_of_node[1000];
int Size=0;
int tree_result(node &a,node &b)
{
    int res=0;
    if(b.child_num>2)
        a.isbtree=false;
    if(b.father_num>2)
        a.is_graph=true;
    if(data[b.num].isget==true)
    {
        a.is_graph=true;
        return 0;
    }
    data[b.num].isget=true;
    if(b.child_num==0)
    {
        Size++;
        return b.num;
    }
    Size++;
    for(int i=0; i<b.child_num; i++)
    {
        res+=tree_result(a,data[b.child[i]]);
    }
    res+=b.num;
    return res;
}
void fuyuan(node &a,node &b)
{

    data[b.num].isget=false;
    if(b.child_num==0)
    {
        return;
    }
    for(int i=0; i<b.child_num; i++)
    {
        fuyuan(a,data[b.child[i]]);
    }
    return;
}
int graph_result(node &a)
{
    int res=0;
    if(data[a.num].isget==true)
        return 0;
    data[a.num].isget=true;
    Size++;
    for(int i=0; i<a.child_num; i++)
        res+=graph_result(data[a.child[i]]);
    for(int i=0; i<a.father_num; i++)
        res+=graph_result(data[a.father[i]]);
    res+=a.num;
    return res;

}
void swapr(r &a,r &b)
{
    int tmpres=0,tmpsize=0;
    tmpres=a.res;
    tmpsize=a.size;
    a.res=b.res;
    a.size=b.size;
    b.res=tmpres;
    b.size=tmpsize;
    return;
}
void sortr(r a[100],int length)
{
    for(int i=0; i<length; i++)
        for(int j=i; j<length; j++)
            if(a[j].res<a[i].res||(a[j].res==a[i].res&&a[j].size<a[i].size))
                swapr(a[j],a[i]);
    return;
}
int main()
{
    char *str;
    str=new char[1000];
    int headnode[1000]= {0};
    int headnode_num=0;
    int point_position=0,position=0;
    cin.getline(str,1000);
    int length=strlen(str);
    for(int k=0; k<length; k+=position+2)
    {
        if(strlen(str)==2)
        {
            cout<<"We have recognized 0 graph.";
            return 0;
        }
        for(int i=0; str[i]!='\0'; i++)
        {
            if(str[i]==' '&&str[i+1]>='0'&&str[i+1]<='9')
                point_position=i;
            if(str[i]=='>'&&str[i+1]=='\0')
            {
                position=i;
                break;
            }
            if(i>1&&str[i-1]==' '&&str[i]=='<')
            {
                position=i-2;
                break;
            }

        }
        if(point_position==0)
        {
            {
                data[stoi(str+1)].ishead=true;
                data[stoi(str+1)].num=stoi(str+1);
                headnode[headnode_num]=stoi(str+1);
                headnode_num++;
            }
        }
        else
        {
            data[stoi(str+1)].father[data[stoi(str+1)].father_num]=stoi(str+point_position+1);
            data[stoi(str+1)].num=stoi(str+1);
            data[stoi(str+point_position+1)].child[data[stoi(str+point_position+1)].child_num]=stoi(str+1);
            data[stoi(str+point_position+1)].num=stoi(str+point_position+1);
            data[stoi(str+1)].father_num++;
            data[stoi(str+point_position+1)].child_num++;
        }
        str+=position+2;
        point_position=0;
    }
    int nodenum=0,treenum=0,btreenum=0,graphnum=0,result=0;
    for(int i=0; i<headnode_num; i++)
    {
        if(data[headnode[i]].child_num==0)
        {
            res_of_node[nodenum].res=headnode[i];
            data[headnode[i]].isget=true;
            nodenum++;
            continue;
        }
        result=tree_result(data[headnode[i]],data[headnode[i]]);
        if(data[headnode[i]].is_graph==true)
        {
            Size=0;
            fuyuan(data[headnode[i]],data[headnode[i]]);
            result=graph_result(data[headnode[i]]);
            res_of_graph[graphnum].res=result;
            res_of_graph[graphnum].size=Size;
            graphnum++;
            Size=0;
            continue;
        }
        if(data[headnode[i]].isbtree==true)
        {
            res_of_binarytree[btreenum].res=result;
            res_of_binarytree[btreenum].size=Size;
            Size=0;
            btreenum++;
            continue;
        }
        else
        {
            res_of_tree[treenum].res=result;
            res_of_tree[treenum].size=Size;
            Size=0;
            treenum++;
            continue;
        }
    }
    for(int i=0; i<10000; i++)
    {
        if(data[i].num!=-1&&data[i].isget==false)
        {
            result=graph_result(data[i]);
            res_of_graph[graphnum].res=result;
            res_of_graph[graphnum].size=Size;
            graphnum++;
            Size=0;
        }
    }
    sortr(res_of_binarytree,btreenum);
    sortr(res_of_graph,graphnum);
    sortr(res_of_node,nodenum);
    sortr(res_of_tree,treenum);
    if(btreenum+graphnum+nodenum+treenum==1)
        cout<<"We have recognized "<<1<<" graph."<<endl;
    else
        cout<<"We have recognized "<<btreenum+graphnum+nodenum+treenum<<" graphs."<<endl;
    for(int i=0; i<nodenum; i++)
    {
        cout<<"--Node. Weight: "<<res_of_node[i].res<<". Size: 1.";
        if(i!=nodenum-1)
            cout<<endl;
    }
    for(int i=0; i<btreenum; i++)
    {
        if(nodenum!=0&&i==0)
            cout<<endl;
        cout<<"--Binary tree. Weight: "<<res_of_binarytree[i].res<<". Size: "<<res_of_binarytree[i].size<<'.';
        if(i!=btreenum-1)
            cout<<endl;
    }
    for(int i=0; i<treenum; i++)
    {
        if((nodenum!=0||btreenum!=0)&&i==0)
            cout<<endl;
        cout<<"--Tree. Weight: "<<res_of_tree[i].res<<". Size: "<<res_of_tree[i].size<<'.';
        if(i!=treenum-1)
            cout<<endl;
    }
    for(int i=0; i<graphnum; i++)
    {
        if((nodenum!=0||btreenum!=0||treenum!=0)&&i==0)
            cout<<endl;
        cout<<"--Graph. Weight: "<<res_of_graph[i].res<<". Size: "<<res_of_graph[i].size<<'.';
        if(i!=graphnum-1)
            cout<<endl;
    }

    return 0;
}
