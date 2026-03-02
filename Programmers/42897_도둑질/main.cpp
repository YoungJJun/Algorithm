#include <string>
#include <vector>
#include <iostream>
using namespace std;

int max(int a, int b, int c){
    int m = a;
    if(m<b) m=b;
    if(m<c) m=c;

    return m;
}

int solution(vector<int> money) {

    int n = money.size();

    vector<int> includeFirst(n, 0);
    vector<int> excludeFirst(n, 0);

    includeFirst[0] = includeFirst[1] = money[0];
    excludeFirst[1] = money[1];

    int result = 0;
    for(int i=2; i<n; i++){
        includeFirst[i] = max(includeFirst[i-2] + money[i], includeFirst[i-1]);
        excludeFirst[i] = max(excludeFirst[i-2] + money[i], excludeFirst[i-1]);

        if(i == n-1){
            result = max(result, excludeFirst[i]);
            continue;
        }
        result = max(result, includeFirst[i], excludeFirst[i]);
    }

    return result;
}