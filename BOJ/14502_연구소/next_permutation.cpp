#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/**
 * Correct는 받았지만 임의로 벽을 3개 생성하는 경우에 비효율적인 풀이 방법인 것 같음.
 * 백트래킹으로 풀이하는게 더 효율적이라고 생각.
 * 코딩 테스트 느낌으로 시간을 정하고 풀이했기 때문에 생각나는대로 우선 진행했고 백트래킹 이용해 다시 풀어보면 좋을 것 같음.
 */
using namespace std;
int rows, cols;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int result = -1;

void spread(vector<vector<int>> map, vector<pair<int, int>> &virus) {

    vector<vector<bool>> visited (rows, vector<bool>(cols, false));
    queue<pair<int, int>> q;

    for (int i=0; i<virus.size(); i++) {
        q.emplace(virus[i].first, virus[i].second);
    }

    // BFS
    while (!q.empty()) {

        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int ny = curY + dy[i];
            int nx = curX + dx[i];

            if (ny >= 0 && ny < rows && nx >= 0 && nx < cols && !visited[ny][nx] && map[ny][nx] != 1) {
                map[ny][nx] = 2;
                q.emplace(ny, nx);
                visited[ny][nx] = true;
            }
        }
    }

    // 살아남은 칸 체크 후 최신화
    int tmp = 0;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (map[i][j] == 0) tmp++;
        }
    }

    result = max(result,tmp);

}

int main() {

    cin >> rows >> cols;
    vector<vector<int>> map(rows, vector<int>(cols));
    vector<pair<int,int>> empty;
    vector<pair<int,int>> virus;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin>>map[i][j];
            if (map[i][j] == 0) {
                empty.emplace_back(i, j);
            }
            else if (map[i][j] == 2 ) {
                virus.emplace_back(i, j);
            }
        }
    }

    // next permutation 준비
    vector<int> select(empty.size() - 3, 0);
    for (int i=0; i < 3; i++) {
        select.push_back(1);
    }

    // 3가지 선택상황 생성
    queue<int> q;
    do {
        for (int i=0; i<select.size(); i++) {
            if (select[i] == 1) {
                q.push(i);
                map[empty[i].first][empty[i].second] = 1;
            }
        }

        spread(map, virus);

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            map[empty[i].first][empty[i].second] = 0;
        }

    }while (next_permutation(select.begin(), select.end()));

    cout<<result;

}