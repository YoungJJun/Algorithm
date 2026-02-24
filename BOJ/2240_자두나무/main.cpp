#include <iostream>
#include <vector>
using namespace std;

int T,W;
int input;

int main() {
    cin>>T>>W;
    vector<vector<int>> dp(T, vector<int>(W+1, 0));

    cin>>input;
    for (int col=0; col<W+1; col++) {
        if (input == 1) {
            if (col % 2 == 0) dp[0][col] = 1;
        }
        else {
            if (col % 2 == 1) dp[0][col] = 1;
        }
    }


    for (int i=1; i<T; i++) {
        cin>>input;

        for (int j=0; j<W+1; j++) {
            bool isCollinear;
            if ((j % 2) + 1 == input ) isCollinear = true;
            else isCollinear = false;

            if (j==0) {
                if (isCollinear) dp[i][j] = dp[i-1][j] + 1;
                else dp[i][j] = dp[i-1][j];

                continue;
            }

            // 열매와 내 위치가 일치하면
            // 이동하지 않고 열매를 받는 경우와 이동해서 열매를 받는 경우를 비교해 큰 값 선택
            if (isCollinear) {
                dp[i][j] = max(dp[i-1][j] + 1, dp[i-1][j-1] + 1);
            }
            // 열매와 내 위치가 일치하지 않으면
            // 이동하지 않고 열매를 받지 않는 경우와 이동해서 열매를 받는 경우를 비교해 큰 값 선택
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + 1);
            }
        }
    }


    int result = dp[T-1][0];
    for (int j=1; j<W+1; j++) {
        result = max(result, dp[T-1][j]);
    }
    cout<<result;

}