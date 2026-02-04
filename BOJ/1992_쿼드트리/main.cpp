#include <iostream>
#include <vector>
using namespace std;
int N;
vector<string> v;

void f(int size, int row, int col) {

    // 1칸인 경우
    if (size == 1) {
        cout<<v[row][col];
        return;
    }

    // 확인
    int sum = 0;
    for (int i=row; i < row + size; i++) {
        for (int j=col; j < col + size; j++) {
            sum += v[i][j]-48;
        }
    }

    if (sum == 0) {
        cout<<0;
        return;
    }
    if (sum == size * size) {
        cout<<1;
        return;
    }

    // 0, 1 석여있으면
    cout<<'(';
    f(size/2, row, col);
    f(size/2, row, col+size/2);
    f(size/2, row+size/2, col);
    f(size/2, row+size/2, col+size/2);

    cout<<')';
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin>>v[i];
    }

    f(N, 0, 0);

}