#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> matrix(N+1, vector<int>(10, 1));
    for (int row=1; row<=N; row++) {
        for (int col=0; col<10; col++) {

            if (col==0) matrix[row][col] = matrix[row-1][col] % 10007;

            else {
                matrix[row][col] = (matrix[row][col-1] + matrix[row-1][col]) % 10007;
            }
        }
    }

    cout<<matrix[N][9];
}