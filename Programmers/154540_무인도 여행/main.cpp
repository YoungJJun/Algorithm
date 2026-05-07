#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};

int sum = 0;

void DFS(int y, int x, vector<vector<bool>> &visited, vector<string> &maps){
    visited[y][x] = true;
    sum += maps[y][x] - 48;

    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(0<=ny && ny<maps.size() && 0<=nx && nx<maps[0].size()){
            if(!visited[ny][nx] && maps[ny][nx] != 'X'){
                DFS(ny, nx, visited, maps);
            }
        }
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    int y = maps.size();
    int x = maps[0].size();
    vector<vector<bool>> visited(y, vector<bool>(x, false));

    //전체에 대해 최소 1회씩은 방문?
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            if(visited[i][j] == false && maps[i][j] != 'X'){
                DFS(i, j, visited, maps);
                answer.push_back(sum);
                sum = 0;
            }
        }
    }

    //빈 상황 처리 && 오름차순
    if(answer.empty()){
        answer.push_back(-1);
    }
    else{
        sort(answer.begin(), answer.end());
    }

    return answer;
}