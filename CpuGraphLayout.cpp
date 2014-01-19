#include "CpuGraphLayout.h"

CpuGraphLayout::CpuGraphLayout(Graph &g) {
    graph = &g;
    
    initial_placement();
    
    ARF_layout();
}

void CpuGraphLayout::initial_placement() {
    int width = floor(sqrt(graph->size()));
    pos.resize(graph->size());
    for (int i = 0; i < pos.size(); i++)
        pos[i] = {(double)(i/width), (double)(i%width)};
}

void CpuGraphLayout::ARF_layout() {
    const double a = 5;
    const double b = 100;
    const double d_t = 0.01;
    
    double error_end = 1;
    double error;
    int iteracie = 0;
    do {
        iteracie++;
        error = 0;
        
        for (int i = 0; i < graph->size(); i++) {
            Point x = {0, 0};
            for (int j = 0; j < graph->size(); j++) {
                if (i!=j) {
                    double K = (graph->connected(i,j) || graph->connected(j, i)) ? a : 1;
                    Point v = pos[j] - pos[i];
                    x = x + (K - b * sqrt(graph->size())/abs(v))*v;
                }
            }
            pos[i] = pos[i] + d_t*x;
            error += abs(x);
        }
        
    } while (error > error_end);
    cout << "iter: " << iteracie << endl;
}


CpuGraphLayout::~CpuGraphLayout() {
}

