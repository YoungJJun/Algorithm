#include <iostream>
#include <vector>
using namespace std;

void dfs(int cur, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[cur] = true;

    for (auto next : adj[cur]) {
        if (!visited[next]) dfs(next, adj, visited);
    }
}

int main() {

    int computers;
    int N;
    cin >> computers >> N;
    vector<vector<int>> adj(computers+1);

    while (N--) {
        int a,b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(computers+1, false);
    dfs(1, adj, visited);

    // 전염된 노드 수 count
    int cnt = 0;
    for (int i = 2; i <= computers; i++) {
        if (visited[i] == true) cnt++;
    }

    cout<< cnt;
}