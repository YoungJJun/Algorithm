#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 * 3차원 BFS 문제
 * 입력을 즉시 dist에 반영해서 입력하는 방식으로 수정가능
 * 이에따라 관련 조건문들도 간단하게 수정가능
 *
 * Pos가 위치만을 저장하기 때문에 Tuple을 사용했어도 될 것 같음 (풀이하는 동안 tuple의 존재를 잊음)
 */


int dy[6] = {0,0,0,0,1,-1};
int dx[6] = {0,0,1,-1,0,0};
int dz[6] = {1,-1,0,0,0,0};

struct Pos {
    int y;
    int x;
    int z;
    Pos(int y, int x, int z) {
        this->y = y;
        this->x = x;
        this->z = z;
    }
};

int main() {
    int rows, cols, heights;
    cin >> cols >> rows >> heights;

    queue<Pos> q;
    vector<vector<vector<int>>> matrix(rows, vector<vector<int>>(cols, vector<int>(heights, 0)));
    vector<vector<vector<int>>> dist(rows, vector<vector<int>>(cols, vector<int>(heights, -1)));
    for (int i = 0; i < heights; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k=0; k<cols; k++) {
                cin >> matrix[j][k][i];
                if (matrix[j][k][i] == 1) {
                    dist[j][k][i] = 0;
                    q.push(Pos(j,k,i));
                }
                if (matrix[j][k][i] == -1) {
                    dist[j][k][i] = -1;
                }
            }
        }
    }


    while (!q.empty()) {
        Pos pos = q.front();
        q.pop();

        for (int i=0; i<6; i++) {
            int ny = pos.y + dy[i];
            int nx = pos.x + dx[i];
            int nz = pos.z + dz[i];

            if (ny >= 0 && nx >= 0 && nz >= 0 && ny < rows && nx < cols && nz < heights) {
                if (dist[ny][nx][nz] == -1 && matrix[ny][nx][nz] == 0) {
                    q.push(Pos(ny,nx,nz));
                    dist[ny][nx][nz] = dist[pos.y][pos.x][pos.z] + 1;
                }
            }
        }
    }

    bool possible = true;
    int m = -1;
    for (int i = 0; i < heights; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k=0; k<cols; k++) {
                if (matrix[j][k][i]!=-1 && dist[j][k][i] == -1) {
                    possible = false;
                    break;
                }
                m = max(m, dist[j][k][i]);
            }

        }
    }
    if (possible) {
        cout<<m;
    }
    else {
        cout<< -1;
    }


}