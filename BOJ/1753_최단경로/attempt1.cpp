#include <iostream>
#include <vector>
#include <limits>
using namespace std;


int V,E;
int start;
int a,b,c;
const int INF = numeric_limits<int>::max();


vector<int> dijkstra(int start,vector<vector<int>> &adjMatrix) {

    vector<int> distance(V+1,INF);
    vector<bool> visited(V+1,false);
    distance[start] = 0;

    for (int i=1; i<=V; i++) {
        int u=-1;
        for (int j=1; j<=V; j++) {
            if (!visited[j] && (u==-1 || distance[j] < distance[u])) {
                u = j;
            }
        }
        if (distance[u]==INF || u==-1) {break;}
        visited[u] = true;

        for (int v=1; v<=V; v++) {
            if (adjMatrix[u][v] != INF && distance[u] + adjMatrix[u][v] < distance[v]) {
                distance[v] = distance[u] + adjMatrix[u][v];
            }
        }
    }

    return distance;

}

int main() {

    cin>>V>>E>>start;
    vector<vector<int> > adjMatrix(V+1, vector<int>(V+1,INF));

    for (int i = 0; i < E; i++) {
        cin>>a>>b>>c;
        adjMatrix[a][b]=c;
    }


    vector<int> ans = dijkstra(start,adjMatrix);
    for (int i=1; i<=V; i++) {
        int tmp = ans[i];
        if (ans[i] == INF) {
            cout<<"INF"<<endl;
        }
        else {
            cout<<tmp<<endl;
        }
    }



}