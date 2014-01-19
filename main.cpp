#include <iostream>
#include "Graph.h"
#include "CpuGraphLayout.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc == 3) {
        Graph g (argv[1]);
        CpuGraphLayout l (g);
        l.export_to_svg(argv[2]);
    }
    else {
        Graph g ("graf4.txt");
        CpuGraphLayout l (g);
        l.export_to_svg("out2.svg");
    }
}

