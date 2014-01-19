#ifndef GRAPH_H
#define	GRAPH_H

#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

class Graph {
public:
    Graph(char * filename);
    Graph(int n);
    virtual ~Graph();
    bool connected(int i, int j);
    void connect(int i, int j);
    int size();
private:
    int n;
    vector< vector<bool> > adjacency;
};

#endif	/* GRAPH_H */

