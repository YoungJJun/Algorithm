#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e8;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0 , 0};

struct Node {
    int row;
    int col;
    bool done;
    Node(int r,int c, bool done) {
        row = r;
        col = c;
        this->done = done;
    }
};

vector<vector<vector<int>>> dist;

int main() {
    int N, M;
    cin >> N >> M;

    dist.resize(N, vector<vector<int>>(M, vector<int>(2, INF)));
    vector<vector<char>> matrix(N, vector<char>(M));
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        for (int j=0; j<M; j++) {
            matrix[i][j] = s[j];
        }
    }

    queue<Node> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;

    while (!q.empty()) {
        int curRow = q.front().row;
        int curCol = q.front().col;
        bool curDone = q.front().done;
        q.pop();

        for (int i=0; i<4; i++) {
            int nextRow = curRow + dy[i];
            int nextCol = curCol + dx[i];



            if (nextRow >= 0 && nextRow < N && nextCol >= 0 && nextCol < M) {
                if (matrix[nextRow][nextCol] == '1' && curDone == 1) {
                    continue;
                }
                if (matrix[nextRow][nextCol] == '1' && curDone == false && dist[nextRow][nextCol][true] > dist[curRow][curCol][false] + 1) {
                    dist[nextRow][nextCol][true] = dist[curRow][curCol][false] + 1;
                    q.push(Node(nextRow, nextCol, true));
                    continue;
                }
                if (matrix[nextRow][nextCol] == '0' && curDone == true && dist[nextRow][nextCol][true] > dist[curRow][curCol][true] + 1) {
                    dist[nextRow][nextCol][true] = dist[curRow][curCol][true] + 1;
                    q.push(Node(nextRow, nextCol, true));
                    continue;
                }
                if (matrix[nextRow][nextCol] == '0' && curDone == false &&  dist[nextRow][nextCol][false] > dist[curRow][curCol][false] + 1) {
                    dist[nextRow][nextCol][false] = dist[curRow][curCol][false] + 1;
                    q.push(Node(nextRow, nextCol, false));
                    continue;
                }
            }
        }
    }


    int minDist = INF;
    if (minDist > dist[N-1][M-1][0]) minDist = dist[N-1][M-1][0];
    if (minDist > dist[N-1][M-1][1]) minDist = dist[N-1][M-1][1];

    if (minDist == INF) {
        cout<<-1;
    }
    else {
        cout<<minDist;
    }
}