#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

void pad(vector<string> &storage){
     int cols = storage[0].size();

    string s;
    for(int i=0 ; i<cols+2; i++){
        s += ".";
    }
    storage.push_back(s);
    storage.insert(storage.begin(), s);
    for(int i=1; i<storage.size()-1; i++){
        storage[i] = "."+storage[i]+".";
    }
}

void checkAll(vector<string> &storage, char target){
    for(auto &s : storage){
        for(char &c : s){
            if(c==target) c='.';
        }
    }
}

void BFS(vector<string> &storage, char target){

    vector<vector<bool>> visited (storage.size(), vector<bool>(storage[0].size(), false));
    queue<pair<int,int>> q;
    queue<pair<int,int>> del;
    q.emplace(0,0);
    visited[0][0] = true;

    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = curY + dy[i];
            int nx = curX + dx[i];

            if(ny >= 0 && nx>=0 && ny<storage.size() && nx<storage[0].size() && visited[ny][nx] == false){
                if(storage[ny][nx] == target){
                    visited[ny][nx] = true;
                    del.emplace(ny,nx);
                }
                else if(storage[ny][nx] == '.'){
                    visited[ny][nx] = true;
                    q.emplace(ny,nx);
                }
            }
        }

    }

    while(!del.empty()){
        int y = del.front().first;
        int x = del.front().second;
        del.pop();

        storage[y][x] = '.';
    }

}

int solution(vector<string> storage, vector<string> requests) {

    // 패딩 추가
    pad(storage);

    // 요청 길이에 따라 처리
    for(string s : requests){

        // 전체탐색 (2중 for) 하면서 삭제
        if(s.size() == 2){
            checkAll(storage, s[0]);
        }
        // 0,0부터 도달가능한 부분만 삭제
        else{
            BFS(storage, s[0]);
        }
    }

    // 삭제되지 않은 값 count 후 출력
    int answer = 0;
    for(auto s: storage){
        for(auto c: s){
            if(c!='.') answer++;
        }
    }
    return answer;
}