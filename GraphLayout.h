#ifndef GRAPHLAYOUT_H
#define	GRAPHLAYOUT_H

#include <vector>
#include <iostream>
#include <cmath>
#include "Graph.h"
#include "Point.h"
using namespace std;

class GraphLayout {
public:
    void export_to_svg(char * filename);
protected:
    vector< Point > pos;
    Graph * graph;
private:
    void normalize(int width, int height, int offset);
    
    FILE* f;
    void init_svg(char * filename);
    void finalize_svg();
    void draw_circle(Point & s);
    void draw_arrow(Point & a, Point & b);
};

#endif	/* GRAPHLAYOUT_H */

