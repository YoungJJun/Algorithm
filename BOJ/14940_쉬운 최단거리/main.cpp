#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e8;

int row, col;
int goalY, goalX;

int ny[4] = {0, 0, 1, -1};
int nx[4] = {1, -1, 0, 0};
vector<vector<int>> matrix;
vector<vector<int>> dist;

void BFS() {
    queue<pair<int, int>> q;
    q.emplace(goalY, goalX);
    dist[goalY][goalX] = 0;

    while (!q.empty()) {
        auto pos = q.front();
        int curY = pos.first;
        int curX = pos.second;
        q.pop();

        for (int i=0; i<4; i++) {
            int nextY = curY + ny[i];
            int nextX = curX + nx[i];

            if (nextY >= 0 && nextY < row && nextX >= 0 && nextX < col) {
                if (matrix[nextY][nextX] == 1 && dist[nextY][nextX] == INF) {
                    dist[nextY][nextX] = dist[curY][curX] + 1;
                    q.emplace(nextY, nextX);
                }
            }
        }
    }

    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (dist[i][j] == INF && matrix[i][j] == 0) dist[i][j] = 0;
            if (dist[i][j] == INF && matrix[i][j] == 1) dist[i][j] = -1;
        }
    }
}

int main() {

    cin >> row >> col;

    matrix.resize(row, vector<int>(col));
    dist.assign(row, vector<int>(col,INF));
    for (int i = 0 ; i < row; i++) {
        for (int j = 0 ; j < col; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 2) {
                goalY = i;
                goalX = j;
            }
        }
    }

    BFS();

    for (int i = 0 ; i < row; i++) {
        for (int j = 0 ; j < col; j++) {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

}