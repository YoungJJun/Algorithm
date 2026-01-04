#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {

    //최대 30가지 clothes
    //각 위치별 개수 저정벡터
    vector<int> cnt (30, 0);
    unordered_map <string,int> map;


    //아이템 착용 위치 string -> id변경 후
    //각 위치별 아이템 수 계산
    int id = 0;
    for(auto x : clothes){

        if(map.find(x[1]) == map.end()){
            map[x[1]] = id;
            id++;
        }

        int i = map[x[1]];
        cnt[i]++;
    }


    //아이템이 A위치 3개 B위치 2개라고 가정하면
    //A위치에서 3가지 + 착용하지 않음 1가지 = 4가지 가능
    //B위치 또한 2 + 1 = 3가지 가능
    //전체적으로 보면 아무것도 착용하지 않는 경우 포함 따라서 -1
    int result = 1;
    for(auto n : cnt){
        if(n==0) continue;
        result *= n+1;
    }
    return result-1;


}