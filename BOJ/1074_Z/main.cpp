#include <iostream>
#include <vector>
using namespace std;

int N,r,c;
long long result;

void quadrant(int len) {
    if (len == 1) return;

    if (len/2 <= r) {
        if (len/2 <= c) {
            // 4사분면
            result += len * len /4 * 3;
            r -= len/2;
            c -= len/2;
            quadrant(len/2);
        }
        else {
            // 3사분면
            result += len * len / 2;
            r -= len / 2;
            quadrant(len/2);
        }
    }
    else {
        if (len/2 <= c) {
            // 1사분면
            result += len * len / 4;
            c -= len/2;
            quadrant(len/2);
        }
        else {
            // 2사분면
            result += 0;
            quadrant(len/2);
        }
    }
}

int main() {

    cin >> N >> r >> c;
    result = 0;
    quadrant(1 << N);
    cout << result << endl;

}