#include <string>
#include <vector>
#include <queue>
using namespace std;

bool canChange(string a, string b){
    int cnt = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]) cnt++;
    }
    if(cnt == 1) return true;
    else return false;
}

int solution(string begin, string target, vector<string> words) {
    int n = words.size();
    vector<bool> visited(n, false);
    queue<pair<string, int>> q; //string까지 int번 바꿔야 함을 의미

    q.emplace(begin, 0); //시작은 0

    while(!q.empty()){
        string curWord = q.front().first;
        int cost = q.front().second;
        q.pop();

        //현재 단어가 target까지 도달했으면 그 때의 cost return
        if(curWord==target) return cost;

        //현재 단어기준
        //다음 단어를 탐색해서 queue에 삽입하는데
        //변경가능(1글자만 다름), !visited 일 때만 queue에 삽입
        for(int i=0; i<n; i++){
            if(!visited[i] && canChange(curWord,words[i])){
                visited[i] = true;
                q.emplace(words[i],cost+1);
            }
        }
    }

    //모두 visit 했지만 target에 도달하지 못했다면 return 0 -> 불가능
    return 0;

}