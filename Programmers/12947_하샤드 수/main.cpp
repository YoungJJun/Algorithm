#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(int x) {
    int result = 0;
    int temp = x;

    while(temp!=0){
        result += temp % 10;
        temp /= 10;
    }

    if( x % result == 0 ) return true;
    else return false;

}