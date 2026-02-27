#include <string>
#include <vector>
#include <iostream>
using namespace std;

/**
 * 루트가 정해지지 않았기 때문에 임의로 1번 노드를 루트로 설정
 * 전체 탐색을 통해 잘랐을 때 나누어진 두 트리의 노드 수 차이를 계산
 *
 * 루트가 정해지지 않은 문제에서 1번 노드를 임의로 루트로 설정하게 되었기 때문에
 * 주어진 간선들을 무방향X 양방향O 으로 삽입해야 하는 부분에서 실수가 있었음
 */
vector<vector<int>> adj;
vector<bool> visited;
vector<int> sons;
vector<int> del;

int DFS(int cur, vector<vector<int>> &wires){
    visited[cur] = true;

    int sonCount = 1;
    for(int i=0; i<adj[cur].size(); i++){
        if(!visited[adj[cur][i]]){
            sonCount += DFS(adj[cur][i], wires);
        }
    }

    return sons[cur] = sonCount;
}

int solution(int n, vector<vector<int>> wires) {

    sons.assign(n+1, 0);
    del.assign(n+1, 0);
    adj.assign(n + 1, vector<int>());
    visited.assign(n+1, false);

    for(auto wire : wires){
        adj[wire[0]].push_back(wire[1]);
        adj[wire[1]].push_back(wire[0]);
    }

    DFS(1, wires);

    for(int i=2; i< n + 1; i++){
        del[i] = abs(n - 2 * sons[i]);
    }


    int m = del[2];
    for(int i = 3; i<del.size(); i++){
        m = min (m, del[i]);
    }
    return m;
}