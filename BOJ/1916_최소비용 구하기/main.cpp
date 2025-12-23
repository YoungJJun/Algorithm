#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e8;

int N, M;
int s, e;
vector<int> dist;
vector<vector<pair<int,int>>> graph;

int dijkstra() {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[s] = 0;
    pq.emplace(0, s);

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (auto next : graph[cur]) {
            int next_node = next.first;
            int next_cost = next.second;

            if (dist[next_node] > dist[cur] + next_cost) {
                dist[next_node] = dist[cur] + next_cost;
                pq.emplace(dist[next_node], next_node);
            }
        }
    }

    return dist[e];
}

int main() {
    cin >> N >> M;

    dist.assign(N+1, INF);
    graph.assign(N+1, vector<pair<int,int>>());

    for (int i=0; i<M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    cin >> s >> e;
    cout << dijkstra();
}