#include <iostream>
#include <vector>
using namespace std;

/*
 * dp[0][i]: i번째를 안 마심 (연속 0잔)
 * dp[1][i]: i번째를 마심 (연속 1잔)
 * dp[2][i]: i번째를 마심 (연속 2잔)
 *
 * 이렇게 풀이했는데 이후에 생각해보니 간단하게
 * dp[i] = max(dp[i-1], dp[i-2] + v[i], dp[i-3] + v[i-1] + v[i])
 * 위 점화식으로 풀릴 수 있는 것 같습니다.
 */


int max(int a, int b, int c) {
    int max = a;
    if (max<b) max = b;
    if (max<c) max = c;

    return max;
}

int main() {
    int N;
    cin >> N;

    vector<int> v(N);
    vector<vector<int>> dp(3, vector<int>(N, 0));

    for (int i=0; i<N; i++) {
        cin >> v[i];
    }

    dp[1][0] = v[0];

    for (int col = 1; col < N; col++) {

            int input = v[col];

            dp[0][col] =
                max(dp[0][col-1], dp[1][col-1], dp[2][col-1]);

            dp[1][col] = dp[0][col-1] + input;

            dp[2][col] = dp[1][col-1] + input;
    }

     int result = dp[0][N-1];
     for (int i=1; i<3; i++) {
         result = max(result, dp[i][N-1]);
     }

     cout << result << endl;
}