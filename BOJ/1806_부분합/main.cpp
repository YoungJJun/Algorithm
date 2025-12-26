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

    int i=0, j=0;
    int sum=num[0];

    int ans=N+1;
    while (i<=j) {


        if (ans>j-i+1 && sum >= S) {
            ans=j-i+1;
        }


        if (sum >= S) {
            sum -= num[i];
            if (i+1 == N) {
                break;
            }
            i++;
        }
        else if (sum < S) {

            if (j+1 == N) {
                break;
            }
            j++;
            sum+=num[j];
        }
    }

    if (ans == N+1) {
        cout<<0<<endl;
    }
    else {
        cout<<ans<<endl;
    }
}