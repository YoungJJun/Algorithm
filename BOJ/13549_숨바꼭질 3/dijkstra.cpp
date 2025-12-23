#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e8;

int N,K;
vector<int> dist;
vector<vector<pair<int,int>>> graph;

void dijkstra() {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[N]=0;
    pq.emplace(0, N);

    while (!pq.empty()) {

        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (dist[cur] < cost) continue;

        for (auto next : graph[cur]) {
            int next_cost = next.second;
            int next_node = next.first;

            if (dist[next_node] > dist[cur] + next_cost) {
                dist[next_node] = dist[cur] + next_cost;
                pq.emplace(dist[next_node], next_node);
            }
        }
    }
}
int main() {
    cin >> N >> K;
    dist.assign(100001, INF);
    graph.assign(100001, vector<pair<int,int>>());

    for (int i=0; i<=100000; i++) {
        //한칸 이전으로 이동
        if (i-1 >= 0) graph[i].emplace_back(i-1,1);
        //한칸 다음으로 이동
        if (i+1 < 100001) graph[i].emplace_back(i+1,1);
        //2*X 순간이동
        if (2*i < 100001) graph[i].emplace_back(2*i,0);
    }

    //시작 N 도착 K
    dijkstra();
    cout<<dist[K]<<endl;


}