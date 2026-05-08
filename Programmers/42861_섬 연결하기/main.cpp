#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int u;
    int v;
    int w;

    Edge(int u, int v, int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
    Edge(){}
};

bool comp(Edge &e1, Edge &e2){
    return e1.w<e2.w;
}

vector<int> parent;
int findParent(int x){
    if(x==parent[x]) return x;
    else return parent[x] = findParent(parent[x]);
}
void unionParent(int x, int y){
    x = findParent(x);
    y = findParent(y);

    parent[x] = y;
}

int kruskal(vector<Edge> edges, int v){
    parent.resize(v);
    for(int i=0; i<v; i++){
        parent[i] = i;
    }

    sort(edges.begin(), edges.end(), comp);

    int cost=0;
    int cnt=0;
    for(Edge &e : edges){
        if(findParent(e.u) != findParent(e.v)){
            unionParent(e.u, e.v);
            cost+=e.w;
            cnt++;
        }
        if(cnt==v-1) break;
    }
    return cost;
}

int solution(int n, vector<vector<int>> costs) {

    vector<Edge> edges;

    //costs를 Edge로 변환
    for(int i=0; i<costs.size(); i++){
        int a = costs[i][0];
        int b = costs[i][1];
        int c = costs[i][2];
        edges.emplace_back(a,b,c);
    }

    //Edge를 이용해 MST (kruskal)
    return kruskal(edges, n);

}