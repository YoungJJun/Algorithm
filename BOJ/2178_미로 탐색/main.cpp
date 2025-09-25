#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M; //행, 열
string input;

int yy[4] = {-1,1,0,0};
int xx[4] = {0,0,-1,1};

void BFS(vector<vector<int>> &matrix) {

    vector<vector<int>> dist(N,vector<int>(M,0));
    queue<pair<int,int>> q;

    q.emplace(0,0);
    dist[0][0]=1;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i=0;i<4;i++) {
            int ny = y+yy[i];
            int nx = x+xx[i];

            if (0<=nx && nx<M && 0<=ny && ny<N) {
                if (matrix[ny][nx]==1 && dist[ny][nx]==0) {
                    dist[ny][nx] = dist[y][x] + 1;
                    q.emplace(ny,nx);
                }
            }
        }
    }


    cout<<dist[N-1][M-1]<<endl;


}

int main() {
    cin>>N>>M;
    vector<vector<int>> matrix(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        cin>>input;
        for (int j = 0; j < M; j++) {
            matrix[i][j] = input[j] - '0';
        }
    }

    BFS(matrix);

}