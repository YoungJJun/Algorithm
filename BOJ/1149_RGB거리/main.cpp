#include <iostream>
#include <climits>
#include <vector>
using namespace std;
const int INF = INT_MAX;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> input(N, vector<int>(3, 0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<3; j++) {
            cin >> input[i][j];
        }
    }


    vector<vector<int>> dp(N, vector<int>(3, INF));
    dp[0][0] = input[0][0];
    dp[0][1] = input[0][1];
    dp[0][2] = input[0][2];

    for (int i=1; i<N; i++) {
        for (int j=0; j<3; j++) {
            dp[i][j] = min(dp[i-1][(j+1)%3] + input[i][j], dp[i-1][(j+2)%3] + input[i][j]);
        }
    }

    int min = dp[N-1][0];
    for (int i=1; i<3; i++) {
        if (dp[N-1][i]<min) {
            min = dp[N-1][i];
        }
    }

    cout<<min;

}