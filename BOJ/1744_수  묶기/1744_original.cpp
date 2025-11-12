#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;



int main() {

    //수열의 크기
    int N;
    cin >> N;

    //벡터 생성 후 입력받기
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin>>v[i];
    }


    //정렬
    sort(v.begin(), v.end());


    int result = 0;
    stack<int> st;

    for (int i=0; i<N-1; i=i+2) {
        int a=v[i];
        int b=v[i+1];

        if (a<0 && b<0) {
            result+= a*b;
        }
        else if (a<0 && b==0) {
            result+= a*b;
        }
        else if (a<0 && b>0) {
            result+= a;
            st.push(b);
        }
        else if (a==0 && b==0) {

        }
        else if (a==0 && b==1) {
            result+= b;
        }
        else if (a==1 && b==1) {
            result+= a+b;
        }
        else if (a==1 && b>0) {
            result+= 1;
            st.push(b);
        }
        else if (a==0 && b>0) {
            st.push(b);
        }
        else if (a>0 && b>0) {
            st.push(a);
            st.push(b);
        }
    }
    if (N % 2 == 1) {
        int tmp = v[N-1];
        if (tmp < 0) result+= tmp;
        else if (tmp > 0 ) st.push(tmp);
    }


    while (st.size()>=2) {
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();
        result+= a*b;
    }

    while (!st.empty()) {
        result+= st.top();
        st.pop();
    }


    cout<<result;
    //음수는 음수끼리 묶어서 계산 (절댓값 큰거부터)
    //음수가 짝수개가 아니면 0과 묶음
    //음수는 위 두 상황이 아니면 묶지 않음
    //0은 위 상황에서 쓰이지 않으면 묶지 않음
    //양수는 큰 값부터 묶음
    //1은 묶을 필요 없음?


}