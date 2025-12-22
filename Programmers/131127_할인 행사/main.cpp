#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int min(int a, int b){
    if(a<b) return a;
    else return b;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {

    //전체 필요물품 수 계산
    int total_num = 0;
    for(int n : number){
        total_num += n;
    }

    //맵 생성
    unordered_map<string,int> map;

    //첫날 가입 시 -> 세일 품목별 수 count
    for(int i=0; i<min(10, discount.size()); i++){
        if(map.find(discount[i])==map.end()){
            map[discount[i]]=1;
        }
        else{
            map[discount[i]] += 1;
        }
    }


    //날짜로 반복문 돌리며 계산
    int day = 0;
    int result = 0;

    while(day != discount.size()){

        for(int k=0; k<want.size(); k++){
            if(map.find(want[k]) == map.end() || number[k] > map[want[k]]) break;

            if(k==want.size()-1) result++;
        }

        //다음날로 넘어가기전에
        //오늘의 세일품목은 -
        if(map.find(discount[day]) != map.end()){
            map[discount[day]] -= 1;
        }
        //내일의 세일품목은 +
        if(day+10 < discount.size()){
            if(map.find(discount[day+10])==map.end()) map[discount[day+10]] = 1;
            else map[discount[day+10]] += 1;
        }
        //day++
        day++;

    }


    return result;
}