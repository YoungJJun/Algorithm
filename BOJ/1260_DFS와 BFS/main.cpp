#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int N,M,V;
int a,b;



void DFS(int cur, vector<vector<int> > &adjMatrix,vector<bool> &visited) {
    visited[cur] = true;
    cout<<cur<<" ";
    for (int i=1; i<adjMatrix[cur].size(); i++) {
        if (!visited[i] && adjMatrix[cur][i]==1) {
            DFS(i,adjMatrix,visited);
        }
    }
}




void BFS(int start, vector<vector<int> > &adjMatrix) {
    vector<bool> visited(N+1,false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cout<<cur<<" ";

        for (int i=1; i<adjMatrix[cur].size(); i++) {
            if (!visited[i] && adjMatrix[cur][i]==1) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}




int main() {
    cin>>N>>M>>V;
    vector<vector<int>> adjMatrix(N+1,vector<int>(N+1,0));
    vector<bool> visited(N+1,false);

    for (int i=0;i<M;i++) {
        cin>>a>>b;
        adjMatrix[a][b]=1;
        adjMatrix[b][a]=1;
    }
    DFS(V,adjMatrix,visited);
    cout<<endl;
    BFS(V,adjMatrix);


}