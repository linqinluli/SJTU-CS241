
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <windows.h>
#include "Graph.h"            // get access to our graphics library facilities
#include "hyperelliptic.h"

//------------------------------------------------------------------------------

int main()
{
    using namespace Graph_lib;   // our graphics facilities are in Graph_lib

    hype H;
    H.input();
    H.show_hyoe();

          // give control to the display engine
}

//------------------------------------------------------------------------------
