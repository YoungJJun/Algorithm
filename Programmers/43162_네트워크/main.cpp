#include <string>
#include <vector>
using namespace std;
vector<int> visited;

void dfs(int u, vector<vector<int>> &computers){
    visited[u]=1;

    for(int i=0; i<computers[u].size(); i++){
        if(computers[u][i]==1 && !visited[i]){
            dfs(i,computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    visited.assign(n,0);

    int count=0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            count++;
            dfs(i,computers);
        }
    }

    return count;

}