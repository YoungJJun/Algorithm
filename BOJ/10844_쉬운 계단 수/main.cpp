#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(10, vector<int>(n+1, 0));

    v[0][1] = 0;
    for (int i=1; i<10; i++) {
        v[i][1] = 1;
    }

    for (int col = 2; col <= n; col++) {
        for (int row = 0; row < 10; row++) {
            if (row-1 >= 0 && col-1 >=0) {
                v[row][col] =  (v[row][col] + v[row-1][col-1]) % 1000000000;
            }
            if (row+1 < 10 && col-1 >=0) {
                v[row][col] = (v[row][col] + v[row+1][col-1])% 1000000000;
            }
        }
    }

    int ans=0;
    for (int i=0; i<10; i++) {
        ans = (ans + v[i][n]) % 1000000000;
    }

    cout<<ans;
}