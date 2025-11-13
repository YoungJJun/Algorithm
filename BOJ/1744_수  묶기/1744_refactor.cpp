#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//[음수]
//1. 음수는 절댓값 큰 음수부터 곱할 수 있을 때 두개씩 묶어서 계산
//2. 음수가 홀수개여서 남은경우 0과 곱해서 0만들기

//[0]
//1. 남은 음수와 곱해지는 경우를 제외하고는 묶지 않음

//[1]
//1. 어떤수와 묶어도 그냥 더하는것과 비교해 손해

//[양수]
//1. 절댓값이 큰 양수부터 두개씩 묶어서 계산


int main() {

    //수열의 크기
    int N;
    cin >> N;

    //양수, 음수, 0, 1로 나누어서 입력받기
    vector<int> pos,neg;
    int zero=0, one=0;

    int input;
    for (int i = 0; i < N; i++) {
        cin>>input;
        if (input==1) one++;
        else if (input==0) zero++;
        else if (input>0) pos.push_back(input);
        else neg.push_back(input);
    }

    //정렬
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());



    //계산
    int result=0;

    //음수 계산
    for (int i=0; i+1<neg.size(); i=i+2) {
        result += neg[i] * neg[i+1];
    }
    if (neg.size() % 2 == 1 && zero==0) result += neg[neg.size()-1];

    //양수 계산
    for (int i=0; i+1<pos.size(); i=i+2) {
        result += pos[i] * pos[i+1];
    }
    if (pos.size() % 2 == 1) result += pos[pos.size()-1];

    //1은 항상 더하기
    result += one;

    cout<<result;
}