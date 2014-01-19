#ifndef CPUGRAPHLAYOUT_H
#define	CPUGRAPHLAYOUT_H

#include <iostream>
#include <cmath>
#include "GraphLayout.h"
#include "Graph.h"
#include "Point.h"

class CpuGraphLayout : public GraphLayout {
public:
    CpuGraphLayout(Graph &g);
    virtual ~CpuGraphLayout();
private:
    void initial_placement();
    void ARF_layout();
};

#endif	/* CPUGRAPHLAYOUT_H */

