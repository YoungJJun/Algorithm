#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
const int INF = 1e8;

void dijkstra(int s, vector<vector<pair<int,int>>> &graph, vector<int> &dist){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[s] = 0;
    pq.emplace(0,s);

    while(!pq.empty()){
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if(dist[curNode] < curCost) continue;

        for(auto x : graph[curNode]){
            int nextCost = x.second;
            int nextNode = x.first;

            if(dist[nextNode] > curCost+nextCost){
                dist[nextNode] = curCost + nextCost;
                pq.emplace(dist[nextNode], nextNode);
            }
        }
    }

}

int solution(int n, vector<vector<int>> edge) {

    vector<vector<pair<int,int>>> graph (n+1);
    vector<int> dist(n+1,INF);

    //간선입력
    for(auto x : edge){
        int a = x[0];
        int b = x[1];

        graph[a].emplace_back(b,1);
        graph[b].emplace_back(a,1);
    }

    //다익스트라
    dijkstra(1, graph, dist);

    //최대거리 확인
    int maxDist = -1;
    for(int i=1; i<=n; i++){
        if(dist[i] > maxDist) maxDist = dist[i];
    }

    //최대거리 노드 카운트
    int answer = 0;
    for(int i=1; i<=n; i++){
        if(dist[i] == maxDist) answer++;
    }
    return answer;
}