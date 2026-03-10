#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e8;

/**
 * 도시 i에서 도시 j로 갈 수 없는 경우에는 그 자리에 0을 출력한다
 * 도달 불가능 상황에서 0을 출력하는 부분을 문제에서 놓쳐서 1회 WA
 */
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n+1, vector<int>(n+1, INF));

    // 자신까지의 거리 0
    for (int i=1; i<=n; i++) {
        dist[i][i] = 0;
    }
    // 간선 입력받기
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    // K를 경유하는 모든 경우
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (dist[i][k] == INF || dist[k][j] == INF) continue;

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (dist[i][j] == INF) {
                cout<< 0 << " ";
            }
            else {
                cout << dist[i][j] << " ";
            }
        }
        cout<<"\n";
    }
}