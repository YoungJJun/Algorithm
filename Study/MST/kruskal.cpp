#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//minimum spanning tree - kruskal algorithm

struct Edge {
    int u,v,w;
};
bool comp (const Edge &e1, const Edge &e2) {
    return e1.w < e2.w;
}

vector<int> parent;

int find_parent(int x) {
    if (x==parent[x]) return x;
    else return parent[x] = find_parent(parent[x]);
}

void union_parent(int a, int b) {
    a= find_parent(a);
    b= find_parent(b);

    parent[b]=a;
}

int kruskal( vector<Edge> &edges,int V) {
    sort(edges.begin(),edges.end(),comp);
    parent.resize(V+1);
    for(int i=1;i<=V;i++) {
        parent[i]=i;
    }

    int cost=0;
    int cntEdge=0;

    for (auto &e : edges) {
        if (find_parent(e.u) != find_parent(e.v)) {
            union_parent(e.u,e.v);
            cost+=e.w;
            cntEdge++;
        }
        if (cntEdge == V - 1) break;
    }

    return cost;
}


