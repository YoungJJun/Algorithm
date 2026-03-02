#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll max(ll a, ll b, ll c, ll d) {
    ll m = a;
    if (m < b) m = b;
    if (m < c) m = c;
    if (m < d) m = d;
    return m;
}
ll min(ll a, ll b, ll c, ll d) {
    ll m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    if (d < m) m = d;
    return m;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<ll>> value(rows,vector<ll>(cols, 0));
    vector<vector<int>> color(rows, vector<int>(cols, 0));
    vector<vector<ll>> dpMax(rows, vector<ll>(cols, 0));
    vector<vector<ll>> dpMin(rows, vector<ll>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> value[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> color[i][j];
        }
    }

    dpMax[0][0] = dpMin[0][0] = value[0][0];
    for (int i = 1; i < rows; i++) {
        if (color[i][0] == 0) {
            dpMax[i][0] = dpMax[i-1][0] + value[i][0];
            dpMin[i][0] = dpMin[i-1][0] + value[i][0];
        }
        else {
            dpMax[i][0] = -(dpMax[i-1][0] + value[i][0]);
            dpMin[i][0] = -(dpMin[i-1][0] + value[i][0]);
        }
    }
    for (int i = 1; i < cols; i++) {
        if (color[0][i] == 0) {
            dpMax[0][i] = dpMax[0][i-1] + value[0][i];
            dpMin[0][i] = dpMin[0][i-1] + value[0][i];
        }
        else {
            dpMax[0][i] = -(dpMax[0][i-1] + value[0][i]);
            dpMin[0][i] = -(dpMin[0][i-1] + value[0][i]);
        }
    }


    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {

            ll a = dpMax[i-1][j] + value[i][j];
            ll b = dpMax[i][j-1] + value[i][j];
            ll c = dpMin[i-1][j] + value[i][j];
            ll d = dpMin[i][j-1] + value[i][j];

            if (color[i][j] == 0) {
                dpMax[i][j] = max(a,b,c,d);
                dpMin[i][j] = min(a,b,c,d);
            }
            else {
                dpMax[i][j] = max(-a,-b,-c,-d);
                dpMin[i][j] = min(-a,-b,-c,-d);
            }
        }
    }


    cout<<dpMax[rows-1][cols-1];

}