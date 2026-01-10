#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(string number, int k) {

    stack<char> st;

    //number를 각 단위별로 하나의 값씩 loop
    for(int i = 0 ; i<number.size(); i++){

        char c = number[i];

        //stack은 k가 가능한 선에서 감소하는 형태로 유지
        while(!st.empty() && k>0 && st.top() < c){
            st.pop();
            k--;
        }

        st.push(c);
    }

    //이미 감소하는 형태여서 k가 남았다면 마지막에 처리
    while(k--){
        st.pop();
    }

    //stack의 역순으로 출력
    stack<char> reverse;
    while(!st.empty()){
        reverse.push(st.top());
        st.pop();
    }
    string result;
    while(!reverse.empty()){
        result+=reverse.top();
        reverse.pop();
    }
    return result;
}