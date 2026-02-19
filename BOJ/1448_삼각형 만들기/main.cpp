#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int result = -1;
    for (int i = 2; i < n; i++) {
        if ( v[i] < v[i-1] + v[i-2] ) result = v[i] + v[i-1] + v[i-2];
    }

    cout << result << endl;
}