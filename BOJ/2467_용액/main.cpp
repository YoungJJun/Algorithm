#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//two-pointers 공부
//BOJ 2467

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }


    int i=0, j=N-1;
    int ans1=v[i];
    int ans2=v[j];
    int best = abs(v[j]+v[i]);
    while(i<j) {
        int sum = v[i]+v[j];
        if (abs(sum)<best) {
            best=abs(sum);
            ans1=v[i];
            ans2=v[j];
        }

        if (sum<0) {
            i++;
        }
        else {
            j--;
        }
    }

    cout<<ans1<<" "<<ans2<<endl;
}