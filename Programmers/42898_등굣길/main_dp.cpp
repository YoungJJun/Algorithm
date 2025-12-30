#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {

    vector<vector<int>> map(n+1, vector<int>(m+1,0));

    //물에 잠긴지역 표시
    for(auto x : puddles){
        int col = x[0];
        int row = x[1];

        map[row][col] = -1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){

            //시작지점 1 설정
            if(i==1 && j==1) {
                map[i][j]=1;
                continue;
            }

            //잠긴경우
            if(map[i][j] == -1){
                map[i][j] = 0;
            }
            //기본 로직
            else{
                map[i][j] = (map[i-1][j] + map[i][j-1]) % 1000000007;
            }

        }
    }


    return map[n][m];
}