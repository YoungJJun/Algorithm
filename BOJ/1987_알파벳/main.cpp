#include <iostream>
#include <vector>

using namespace std;

/*
 * 1. 격자 방문 여부를 visited[][]로 체크, map을 이용해 알파벳까지 체크 -> 시간초과
 * 2. map만 이용해도 visited를 체크할 수 있음
 * 3. 알파벳이 최대 A~Z로 고정되었기 때문에 배열로 선언 후 사용하는것이 효율적 -> CORRECT
 */

int rows, cols;
vector<string> input;
bool check[26];

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

int answer = 0;
void DFS(int y, int x, int cnt) {

   char c = input[y][x];
   if (check[c-'A'] == true) return;
   else {
      check[c-'A'] = true;
      answer = max(answer, cnt);
   }


   for (int i=0; i<4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny>=0 && nx>=0 && ny < rows && nx < cols && !check[input[ny][nx]-'A']) {
         DFS(ny, nx, cnt+1);
      }
   }

   check[c-'A'] = false;

}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> rows >> cols;

   input.resize(rows);
   for (int i=0; i<rows; i++) {
      cin>>input[i];
   }


   DFS(0, 0, 1);

   cout<<answer<<"\n";
}