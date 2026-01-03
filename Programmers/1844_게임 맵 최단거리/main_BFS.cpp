#include<vector>
#include<iostream>
#include<queue>
const int INF = 1e8;
using namespace std;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void BFS(int rows, int cols, vector<vector<int>> &dist, vector<vector<int>> &maps){
    queue<pair<int,int>> q;
    q.emplace(0,0);
    dist[0][0]=1;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(0<=nx && nx<cols && 0<=ny && ny<rows && maps[ny][nx] == 1){
                if(dist[ny][nx] > dist[y][x] + 1) {
                    dist[ny][nx]=dist[y][x]+1;
                    q.emplace(ny,nx);
                }
            }
        }
    }

}

int solution(vector<vector<int> > maps)
{
    int rows = maps.size();
    int cols = maps[0].size();
    vector<vector<int>> dist(rows, vector<int>(cols, INF));

    BFS(rows, cols, dist, maps);

    if(dist[rows-1][cols-1] == INF) return -1;
    else return dist[rows-1][cols-1];

}