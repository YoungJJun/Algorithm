#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N,S;
    cin>>N>>S;

    vector<int> num(N);
    for (int i=0; i<N; i++) {
        cin>>num[i];
    }



    int l=0, r=0;
    int sum = 0;
    int ans = N+1; //갱신으로 나올 수 없는 값 -> 그대로이면 결과 불가능 출력

    for (r=0; r<N; r++) {
        sum+=num[r];

        while (sum>=S) {
            ans = min(ans, r-l+1);
            sum-=num[l];
            l++;
        }
    }

    if (ans == N+1) cout<<0<<endl;
    else cout<<ans<<endl;

}