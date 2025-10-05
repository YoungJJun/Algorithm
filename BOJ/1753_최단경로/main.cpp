#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;
int V,E,K;
int u,v,w;

vector<int> dijkstra(vector<vector<pair<int,int>>> & adj) {
    vector<int> dist(adj.size(),INF);
    dist[K]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.emplace(0,K);

    while(!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();

        if (dist[cur_node] < cur_cost) {
            continue;
        }

        for (auto Edge : adj[cur_node]) {
            int next_node = Edge.first;
            int next_cost = Edge.second;

            if (dist[cur_node]+next_cost < dist[next_node]) {
                dist[next_node] = dist[cur_node]+next_cost;
                pq.emplace(dist[next_node],next_node);
            }
        }
    }

    return dist;
}

int main() {
    cin>>V>>E>>K;
    vector<vector<pair<int,int>>> adj(V+1);
    for (int i = 0; i < E; i++) {
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
    }

    vector<int> result = dijkstra(adj);
    for (int i=1; i<=V; i++) {
        if (result[i]==INF) {
            cout<<"INF\n";
        }
        else {
            cout<<result[i]<<"\n";
        }
    }
}