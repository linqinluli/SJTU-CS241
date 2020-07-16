
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
#include "Binary_tree.h"
#include "TriangleBinary_tree.h"
//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    Point tl(100,100);
    Simple_window win(tl,1000,300,"tree");
    int c;
    cout<<"please choose one kind of tree."<<endl<<"1 is for Binary Tree and 2 is for Triangle Binary Tree"<<endl;
    cin>>c;
    if(c==1)
    {
        btree b;
        win.attach(b);
        b.getn();
        b.draw();
        win.wait_for_button();
    }
    else
    {
        Ttree t;
        win.attach(t);
        t.getn();
        t.draw();
        win.wait_for_button();
    }
    return 0;
}

//------------------------------------------------------------------------------
