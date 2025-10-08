#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Edge{
    int u,v,w;
};

vector<int > parent;
int findParent(int x) {
    if(parent[x]==x) return x;
    else return parent[x] = findParent(parent[x]);
}

void unionParent(int x, int y) {
    x=findParent(x);
    y=findParent(y);

    if (x<y) {
        parent[y]=x;
    }
    else {
        parent[x]=y;
    }
}

bool comp(Edge &e1, Edge &e2) {
    return e1.w < e2.w;
}

int kruskal(int V, vector<Edge> &edges) {

    parent.resize(V+1);
    for (int i=1; i<=V; i++) {
        parent[i]=i;
    }
    sort(edges.begin(), edges.end(), comp);

    int totalCost=0;
    int edgeCount=0;
    int maxCost=0;

    for (auto edge : edges) {
        if (findParent(edge.u) != findParent(edge.v)) {
            unionParent(edge.u, edge.v);
            totalCost+=edge.w;
            edgeCount++;
            maxCost=max(maxCost, edge.w);
        }

        if (edgeCount==V+1) break;
    }

    return totalCost-maxCost;
}

int main() {
    int N,M;
    cin>>N>>M;

    int u,v,w;
    vector<Edge> edges;
    for (int i=0; i<M; i++) {
        cin>>u>>v>>w;
        Edge edge;
        edge.u=u;
        edge.v=v;
        edge.w=w;
        edges.push_back(edge);
    }

    cout<< kruskal(N, edges);
}