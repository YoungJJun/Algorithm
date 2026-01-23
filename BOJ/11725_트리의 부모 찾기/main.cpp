#include <iostream>
#include <vector>
using namespace std;
vector<bool> visited;    // 방문여부
vector<int> parent;      // 부모 저장
vector<vector<int>> adj; // 연결 정보

void dfs(int u) {
    visited[u] = true;

    for (auto v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    visited.assign(N+1, false);
    parent.assign(N+1, -1);
    adj.assign(N+1, vector<int>());

    N--;
    while (N--) {
        int a,b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    for (int i=2; i<parent.size(); i++) {
        cout << parent[i] << "\n";
    }
}