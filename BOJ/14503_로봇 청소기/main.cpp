#include <iostream>
#include <vector>
using namespace std;
const int NORTH = 0;
const int SOUTH = 2;
const int EAST = 1;
const int WEST = 3;

const int CLEAN = 2;
const int DIRTY = 0;
const int WALL = 1;

int N,M;
int r,c,d;
int clean = 0;

int dc[4] = {0, 0, 1, -1};
int dr[4] = {1, -1, 0, 0};

void goFrontIfEmptyAndDirty(vector<vector<int>> &status) {
    if (d == NORTH && 0 <= r - 1 && status[r-1][c] == DIRTY) {
        r--;
    }
    else if (d == SOUTH && r + 1 < N && status[r+1][c] == DIRTY) {
        r++;
    }
    else if (d == EAST && c + 1 < M && status[r][c+1] == DIRTY) {
        c++;
    }
    else if (d == WEST && 0 <= c - 1 && status[r][c-1] == DIRTY) {
        c--;
    }
}
bool checkBackIsEmpty(vector<vector<int>> &status) {
    if (d == NORTH) {
        if (r+1 < N && status[r+1][c] != WALL) {
            r++;
            return true;
        }
        else return false;
    }
    else if (d == SOUTH) {
        if ( 0 <= r-1 && status[r-1][c] != WALL) {
            r--;
            return true;
        }
        else return false;
    }
    else if (d == EAST) {
        if ( 0 <= c-1 && status[r][c-1] != WALL) {
            c--;
            return true;
        }
        else return false;
    }
    else if (d == WEST) {
        if ( c+1 < M && status[r][c+1] != WALL) {
            c++;
            return true;
        }
        else return false;
    }

    cout<<"예외";
    return false;
}

bool robot(vector<vector<int>> &status) {
    if (status[r][c] == DIRTY) {
        status[r][c] = CLEAN;
        clean++;
    }

    // 주변 4칸 중 청소되지 않은 칸이 있는지 체크
    bool exist = false;
    for (int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if ( 0 <= nr  &&  nr < N &&  0 <= nc && nc < M  && status[nr][nc] == DIRTY) {
            exist = true;
            break;
        }
    }


    // 청소되지 않은 빈 칸 없으면
    if (!exist) {
        //뒷칸이 비어있지 않으면, 비어있으면 이동 후 1번으로
        if (!checkBackIsEmpty(status)) return false;
        else return true;
    }

    // 청소되지 않은 빈 칸 있으면
    else {

        //회전
        d = d-1;
        if (d==-1) d = 3;

        // 가능하면 이동
        goFrontIfEmptyAndDirty(status);

        return true;


    }
}

int main() {
    //크기, 현위치, 방향 입력
    cin>>N>>M;
    cin>>r>>c>>d;

    // 장소의 상태 입력
    vector<vector<int> > status(N,vector<int>(M,0));
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin>>status[i][j];
        }
    }


    while (robot(status)) {
    }

    cout<<clean;

}