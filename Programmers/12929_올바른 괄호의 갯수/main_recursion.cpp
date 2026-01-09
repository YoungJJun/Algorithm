#include <string>
#include <vector>

using namespace std;
int sum = 0;
void f(int opened, int open, int close){

    //재귀 종료
    if(opened==0 && close==0){
        sum++;
        return;
    }

    if(opened==0){
        f(opened+1, open-1, close);
    }
    else{
        //열려있을 때 닫기
        f(opened-1, open, close-1);
        //열려있을 때 다시 열기
        if(open>0) f(opened+1, open-1, close);

    }

}

int solution(int n) {
    f(0, n, n);

    return sum;
}