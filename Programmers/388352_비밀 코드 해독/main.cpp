#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

/*
 * unordered_map을 생성해 사용하는 것 보다 for문을 이용하는 방법이
 * 전체 조합의 개수가 많아질수록 느려진다는 문제점
 *
 * 현재 데이터 크기에서는 시간초과는 발생하지 않는것으로 보이나 생각해보기
 */

int answer = 0;
vector<int> v;

void check(vector<vector<int>> &q, vector<int> &ans){

    for(int i=0; i<q.size(); i++){
        unordered_map<int,int> map;
        for(auto x : q[i]){
            map[x]++;
        }

        int cnt=0;
        for(auto x: v){
            if(map[x] >= 1) cnt++;
        }

        if(cnt != ans[i]) return;
    }

    answer++;
    return;

}

void comb(int start,int max, vector<vector<int>> &q, vector<int> &ans){
    if(v.size() == 5){
        check(q, ans);
        return;
    }

    for(int i=start; i<=max; i++){
        v.push_back(i);
        comb(i+1, max, q, ans);
        v.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    answer=0;
    v.clear();

    comb(1, n, q, ans);

    return answer;
}