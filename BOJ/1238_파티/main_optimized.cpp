#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e8;

/*

dijkstra -> O(N * M log N)

기존 수행시간 108ms
N+1회의 dijkstra

개선 후 수행시간 4ms
2회의 dijkstra

*/

//변수
int N,M,X;
vector<int> dist;

//다익스트라
void dijkstra(int start,vector<vector<pair<int,int>>> &adj) {
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
    vector<vector<pair<int,int>>> adj(N+1, vector<pair<int,int>>());
    vector<vector<pair<int,int>>> reverseAdj(N+1, vector<pair<int,int>>());
    vector<int> totalCost(N+1,0);

    //간선입력
    for (int i=0; i<M; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        reverseAdj[v].emplace_back(u,w);
    }

    //개선된 부분 : 간선 방향 바꾼 adj에서 dijkstra 1회 수행
    dist.assign(N+1,INF);
    dijkstra(X,reverseAdj);
    for (int i=1; i<=N; i++) {
        totalCost[i] += dist[i];
    }

    dist.assign(N+1,INF);
    dijkstra(X, adj);
    for (int i=1; i<=N; i++) {
        totalCost[i] += dist[i];
    }

    //최댓값 찾아서 출력
    int max = -1;
    for (int i=1; i<=N; i++) {
        if (totalCost[i] > max) {
            max = totalCost[i];
        }
    }
    cout<<max;

}

