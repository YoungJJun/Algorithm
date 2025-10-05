#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


int N, M; //N city M road
const int INF = numeric_limits<int>::max();


int dijkstra(int from, int to,vector<vector<int>> &adj) {
    vector<int> dist(N+1, INF);
    vector<bool> visited(N+1, false);

    dist[from] = 0; //시작점 거리 0
    for (int i=1; i<=N; i++) { //모든 노드에서 한번씩 반복 i값 자체는 필요없음 그저 반복횟수

        //현재노드 기준 가장 가까운 노드를 u로 선택하고 u의 주변 노드들의 거리들을 할당 예정
        int u=-1;
        //현재 노드 기준으로 인접 노드들 중에 가장 가까운 노드 u 선택
        for (int j=1; j<=N; j++) { //각 노드별로 자신과 인접한 모든 노드들에 대해 처리
            if (!visited[j] && (u==-1||dist[j]<dist[u])) {
                u=j;
            }
        }
        //for 이후 가장 가까운 거리였던 노드가 u에 선택 되었음


        if (dist[u]==INF) {break;} //u까지가 가장 가까운 거리인데 INF이면 갈 곳 없음 종료
        visited[u]=true; //u까지 도달 가능하면 방문처리 이 때 u의 최소거리는 확정


        //u를 선택했으니 u를 통해서 갈 수 있는 노드들의 최단거리가 바뀌었을 수 있음 비교 후 할당
        for (int v=1; v<=N; v++) {
            if (adj[u][v]!=INF && dist[u]+adj[u][v]<dist[v]) { //uv가 연결되어 있고 기존 최단거리보다 u를 통해 uv로 가는게 최단인경우
                dist[v]=dist[u]+adj[u][v]; //최단거리로 설정
            }
        }
    }

    if (dist[to]==INF) {
        return -1;
    }
    else {
        return dist[to];
    }

}



