#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
void dijkstra(vector<int> &dist, vector<vector<int>> &adj){
    dist[1]=0;
    queue<pair<int,int>> q;
    for(int i=0; i<adj[1].size(); i++){
        q.emplace(1,adj[1][i]);
    }

    while(!q.empty()){
        int s = q.front().first;
        int e = q.front().second;
        q.pop();

        if(dist[e] == -1 || dist[e] > dist[s] + 1){
            dist[e] = dist[s] + 1;

            for(int i=0; i<adj[e].size(); i++){
                int ee = adj[e][i];
                q.emplace(e, ee);
            }
        }
    }

}

int solution(int n, vector<vector<int>> edge) {

    vector<int> dist(n+1,-1);
    vector<vector<int>> adj(n+1);

    for(auto e : edge){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }


    //다익스트라
    dijkstra(dist, adj);


    //최댓값 확인
    int max = -1;
    for(int x : dist){
        if(x > max) max = x;
    }

    //Count
    int count=0;
    for(int i=1; i<=n; i++){
        if(dist[i] == max) count++;
    }



    return count;
}