#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// O( N + maxValue )
int solution(vector<int> citations) {
    int n = citations.size();
    sort(citations.begin(), citations.end()); //citations의 길이에 따라 순회를 통해 maxValue 구하는게 유리할 수  있음!

    int maxValue = citations[n-1]; //maxValue가 커지게 되면 memory 초과
    vector<int> smaller (maxValue+1, 0);
    vector<int> larger (maxValue+1, 0);

    for(auto x : citations){
        smaller[x]++;
        larger[x]++;
    }

    //누적합
    for(int i=1; i<=maxValue; i++){
        smaller[i] += smaller[i-1];
    }
    for(int i=maxValue-1; i>=0; i--){
        larger[i] += larger[i+1];
    }

    //h-index 찾기
    for(int i=maxValue; i>0; i--){
        if(i<=larger[i] && smaller[i-1]<=i){
            return i;
        }
    }

    return 0;
}


