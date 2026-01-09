#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    //벡터에 각 학생이 가진 체육복 수 계산
    vector<int> cnt1 (n,1);
    for(auto x : lost){
        cnt1[x-1]--;
    }
    for(auto x : reserve){
        cnt1[x-1]++;
    }
    vector<int> cnt2;
    cnt2 = cnt1;


    //상황1 : 왼쪽 우선으로 빌려줌
    for(int i=0; i<n; i++){
        if(cnt1[i]==0 || cnt1[i]==1) continue;

        if(cnt1[i]>1 && i>0 && cnt1[i-1]==0){
            cnt1[i-1]++;
            cnt1[i]--;
        }
         if(cnt1[i]>1 && i+1<n && cnt1[i+1]==0){
            cnt1[i+1]++;
            cnt1[i]--;
        }
    }
    //상황1 계산
    int resultLeft = 0;
    for(auto x : cnt1){
        if(x>=1) resultLeft++;
    }


    //상황2 : 오른쪽 우선으로 빌려줌
    for(int i=n-1; i>=0; i--){
        if(cnt2[i]==0 || cnt2[i]==1) continue;

        if(cnt2[i]>1 && i+1<n && cnt2[i+1]==0){
            cnt2[i+1]++;
            cnt2[i]--;
        }
        if(cnt2[i]>1 && i>0 && cnt2[i-1]==0){
            cnt2[i-1]++;
            cnt2[i]--;
        }
    }
    //상황2 계산
    int resultRight = 0;
    for(auto x : cnt2){
        if(x>=1) resultRight++;
    }


    if(resultLeft<resultRight) return resultRight;
    else return resultLeft;
}