#include "Graph.h"

Graph::Graph(int n) {
    adjacency.resize(n, vector<bool>(n,false));
}

Graph::Graph(char * filename) {
    FILE * f = fopen(filename, "r");
    
    fscanf(f, "%d", &n);
    adjacency.resize(n, vector<bool>(n,false));
    
    int i, j;
    while(fscanf(f, "%d %d", &i, &j)==2) {
        adjacency[i][j] = true;
    }
}

bool Graph::connected(int i, int j) {
    return adjacency[i][j];
}

void Graph::connect(int i, int j) {
    adjacency[i][j] = true;
}

int Graph::size() {
    return n;
}

Graph::~Graph() {
}

