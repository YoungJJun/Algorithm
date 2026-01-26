#include <iostream>
#include <vector>
using namespace std;

int minimum (int a, int b, int c) {
    int min = a;
    if (min>b) min = b;
    if (min>c) min = c;
    return min;
}

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<char>> v(row, vector<char>(col));

    for (int i=0; i<row; i++) {
        string s;
        cin >> s;

        for (int j=0; j<col; j++) {
            v[i][j] = s[j];
        }
    }

    int min = 65;
    for (int r = 7; r < row; r++) {
        for (int c = 7; c < col; c++) {

            // 8 x 8 체스판에 대해 계산
            //좌상단을 W, B 했을 때 칠해야 하는 양 각각 계산
            // ***** 이 부분 로직 단순화 가능 *****
            // a,b 모두 구할필요 없고 64 - a = b
            int a=0;
            int b=0;
            for (int i = r - 7; i <= r; i++) {
                for (int j = c - 7; j <= c; j++) {
                    if ((i+j)%2==0 && v[i][j]!='W') {
                        a++;
                    }
                    if ((i+j)%2==1 && v[i][j]!='B') {
                        a++;
                    }
                    if ((i+j)%2==0 && v[i][j]!='B') {
                        b++;
                    }
                    if ((i+j)%2==1 && v[i][j]!='W') {
                        b++;
                    }
                }
            }

            min = minimum(min, a, b);

        }
    }

    cout << min << endl;

}