#include <string>
#include <vector>
#include <iostream>
using namespace std;

int g(int a, int b){
    if(a % b == 0) return b;
    else return g(b, a%b);
}
int l(int a, int b){
    return (a * b) / g(a,b);
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for(int i = 1; i < arr.size(); i++){
        answer = l(answer, arr[i]);
    }
    return answer;
}