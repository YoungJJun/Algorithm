#include <string>
#include <vector>
#include <queue>
const int INF = 1e8;
using namespace std;

bool canChange(string a, string b){
    int cnt = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]) cnt++;
    }
    if(cnt == 1) return true;
    else return false;
}

void dijkstra(vector<int> &dist, vector<vector<int>> &matrix, int beginIdx){
    dist[beginIdx] = 0;
    queue<int> q;
    q.push(beginIdx);

    while(!q.empty()){
        int curNode = q.front();
        q.pop();

        for(auto next : matrix[curNode]){
            if(dist[next] > dist[curNode]+1){
                dist[next] = dist[curNode]+1;
                q.push(next);
            }
        }
    }

}

int solution(string begin, string target, vector<string> words) {

    //target이 words에 존재하지 않으면 조기 종료
    //존재하면 targetIdx 저장
    int targetIdx = -1;
    bool exist = false;
    for(int i=0; i<words.size(); i++){
        if(words[i] == target){
            exist = true;
            targetIdx = i;
            break;
        }
    }
    if (!exist) return 0;


    //노드 연결
    words.push_back(begin);
    int n = words.size();
    vector<vector<int>> matrix(n);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(canChange(words[i],words[j])){
                matrix[i].push_back(j);
                matrix[j].push_back(i);
            }
        }
    }

    //begin은 맨뒤 idx, target은 targetIdx
    //위 정보 이용해서 dijkstra 수행
    vector<int> dist(n, INF);
    int beginIdx = n-1;
    dijkstra(dist, matrix, beginIdx);

    int result = dist[targetIdx];
    if(result == INF){
        return 0;
    }
    else{
        return result;
    }

}