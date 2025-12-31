#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin>>N>>M;
    vector<vector<int>> matrix(N+1, vector<int>(N+1, 0));
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin>>matrix[i][j];
            matrix[i][j] += matrix[i-1][j]+matrix[i][j-1]-matrix[i-1][j-1];
        }
    }



    while (M--) {
        int x1, y1, x2, y2;
        cin>>y1>>x1>>y2>>x2;

        int a = matrix[y2][x2];
        int minusUp = matrix[y1-1][x2];
        int minusLeft = matrix[y2][x1-1];
        int plus = matrix[y1-1][x1-1];

        cout<<a - (minusUp + minusLeft) + plus <<"\n";
    }
}