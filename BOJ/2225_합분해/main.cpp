#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> matrix(K, vector<int>(N+1, 0));

    //행은 인덱스 K-1까지, 열은 인덱스N까지 접근 가능
    for (int i=0; i<K; i++) {
        matrix[i][0] = 1;
    }
    for (int i=0; i<=N; i++) {
        matrix[0][i] = 1;
    }

    for (int row = 1; row < K; row++) {
        for (int col = 1; col<=N; col++) {
            matrix[row][col] = (matrix[row][col-1] + matrix[row-1][col]) % 1000000000;
        }
    }

    cout<<matrix[K-1][N];

}