#include <iostream>
#include <vector>
using namespace  std;

int N;

void dfs(int node, vector<vector<int>> &matrix, vector<vector<int>> &parent, vector<bool> &visited,vector<int> &depth, int d) {

    visited[node] = true;
    depth[node] = d;

    for (int next : matrix[node]) {
        if (!visited[next]) {
            parent[next][0] = node;
            dfs(next, matrix, parent, visited,depth, d+1);
        }
    }

}

//메인 개념
//높이 맞추고 부모를 체크하면서 모두 탐색하면 TLE
//따라서 위의 과정을 한번에 크게크게 점프를 통해 수행

//어떻게 점프를 많이 뛰면서 최소 공통 조상을 보장하는가
//jump를 멀리(루트에 가깝게) 뛰었는데 a,b의 조상이 같다면 그 지점이 최소공통 일수도 있지만 그 지점보다 아래에 있을수도 있음
//멀리 뛰려고 했을 때 둘의 조상이 같다면 그거보다는 덜 뛴다.
//위 과정을 뛰는 간격을 좁혀가며 반복하다보면 최종적으로는 목표하려는 공통조상보다 하나 아래의 노드까지만 점프를 뛰게된다.
void lca(int a, int b, vector<vector<int>> &parent, vector<int> &depth) {

    //깊이 통일 (a가 더 깊은 상황으로 통일해서 풀이)
    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];

    for (int i = 0; i < 17; i++) {
        if (diff & (1 << i)) a = parent[a][i];
    }

    //깊이를 통일 했을 때 a,b가 같다면 그 값이 공통조상 -> 출력
    if (a == b) {
        cout << a << '\n';
        return;
    }

    //동일 높이부터 점프하며 동일조상 찾기
    int k=16;

    for (; k>=0; k--) {
        if (parent[a][k] != parent[b][k]) {
            a=parent[a][k];
            b=parent[b][k];
        }
    }
    cout<<parent[a][0]<<"\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>N;

    //parent[i]에 i번 노드에 대한 조상의 정보를 담음
    //parent[i][k]는 i번 노드의 2^k 번째 조상
    vector<vector<int>> parent(N+1,vector<int>(17,0));
    vector<vector<int>> matrix(N+1); //노드간 연결관계 입력받는 matrix
    vector<bool> visited(N+1, false); //DFS 수행을 위한 visited
    vector<int> depth(N+1); //각 노드의 depth

    //노드 연결관계 입력받기
    for (int i=0; i<N-1; i++) {
        int a,b;
        cin>>a>>b;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }

    //dfs를 수행하면서 각 노드의 depth 체크, parent 체크
    dfs(1,matrix,parent,visited,depth,0);

    //각 노드의 parent를 기반으로 2의 거듭제곱번째 조상들을 순차적으로 계산
    for (int k=1; k<17; k++) {
        for (int j=1; j<=N; j++) {
            parent[j][k] = parent[parent[j][k-1]][k-1];
        }
    }


    int Test;
    cin>>Test;
    //a,b 의 최소 공통 조상 구해서 출력
    while (Test--) {
        int a,b;
        cin>>a>>b;
        lca(a,b,parent,depth);
    }




}