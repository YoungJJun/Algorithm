#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e8;

//변수
int N,M,X;
vector<int> dist;
vector<vector<pair<int,int>>> adj;

//다익스트라
void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (dist[curNode] < curCost) continue;

        for (auto next : adj[curNode]) {
            int nextCost = next.second;
            int nextNode = next.first;

            if (dist[nextNode] > dist[curNode] + nextCost) {
                dist[nextNode] = dist[curNode] + nextCost;
                pq.emplace(dist[nextNode], nextNode);
            }
        }
    }
}

int main() {
    //입력
    cin>>N>>M>>X;
    //adj 생성
    adj.assign(N+1, vector<pair<int,int>>());
    vector<int> totalCost(N+1,0);

    //간선입력
    for (int i=0; i<M; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
    }

    for (int i=1; i<=N; i++) {
        dist.assign(N+1,INF);
        dijkstra(i);
        totalCost[i] += dist[X];
    }
    dist.assign(N+1,INF);
    dijkstra(X);
    int max = -1;
    for (int i=1; i<=N; i++) {
        totalCost[i] += dist[i];
        if (max < totalCost[i]) max = totalCost[i];
    }

    cout<<max;




}