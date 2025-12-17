#include<iostream>
using namespace std;

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}


int main() {
    int N, K;
    cin >> N >> K;

    int* dp = new int[K + 1]();


    int w, v;

    while (N--) {
        cin >> w >> v;

        for (int i = K; i >=w; i--) {
            dp[i] = max(dp[i - w] + v, dp[i]);
        }


    }

    cout << dp[K];
    delete[] dp;
}