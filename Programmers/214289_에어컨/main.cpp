#include <string>
#include <vector>

using namespace std;

/*
 * 각 시간당 가능한 모든 온도에 대해 유지하기 위한 최소 비용을 저장하도록 DP 테이블를 생성하는 것은 생각했음.
 * a, b 값을 이용해 전이하는 부분 생각했음.


 * 문제 값 범위에 따라 고정 크기를 사용하는게 분기를 줄이고 가독성이 높아질거라고 생각
 * INF 값을 전이를 받는 입장에서 구현해서 i, j 2중 for에서 끝나지 않고 j에 대한 for문을 한 번 더 수행
 * 전이를 보내는 기준으로 코드를 작성하면 전이를 보내지 않으면 INF 유지 가능
 *
 */

const int INF = 1e8;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    vector<vector<int>> v;
    int minTemp;

    if(temperature < t1){
        v.assign(onboard.size(), vector<int>(t2-temperature+1, INF));
        v[0][0] = 0;
        minTemp = temperature;
    }
    else if(t2 < temperature){
        v.assign(onboard.size(), vector<int>(temperature-t1+1, INF));
        v[0][temperature-t1] = 0;
        minTemp = t1;
    }
    else{
        v.assign(onboard.size(), vector<int>(t2-t1+1, INF));
        v[0][temperature-t1] = 0;
        minTemp = t1;
    }


    for(int i=0; i<onboard.size()-1; i++){
        for(int j=0; j<v[i].size(); j++){
            if(v[i][j] == INF) continue;

            if(j-1 >=0) v[i+1][j-1] = min(v[i+1][j-1], v[i][j]+a);
            v[i+1][j] = min(v[i+1][j], v[i][j]+b);
            if(j+1 < v[i].size()) v[i+1][j+1] = min(v[i+1][j+1], v[i][j] + a);

            int curTemp = j + minTemp;
            //끄면 비용없이 온도가 올라가는 상황
            if(curTemp < temperature && j+1 < v[i].size()){
                v[i+1][j+1] = min(v[i+1][j+1], v[i][j]);
            }
            //끄면 비용없이 온도가 내려가는 상황
            if(temperature < curTemp && j-1 >=0){
                v[i+1][j-1] = min(v[i+1][j-1], v[i][j]);
            }
            //끄면 비용없이 온도가 유지되는 상황
            if(curTemp == temperature){
                v[i+1][j] = min(v[i+1][j], v[i][j]);
            }

        }

        if(onboard[i+1] == 1){
            for(int j=0; j<v[i+1].size(); j++){
                int temp = j + minTemp;
                if(temp < t1 || t2 <temp){
                    v[i+1][j] = INF;
                }
            }
        }
    }


    int answer = INF;
    for(int j=0; j<v[0].size(); j++){
        answer = min(answer, v[onboard.size()-1][j]);
    }
    return answer;
}