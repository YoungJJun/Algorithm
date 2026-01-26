#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool op(pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.second != p2.second) return p1.second < p2.second;
    return p1.first < p2.first;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int,int>> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].first;
        cin >> v[i].second;
    }
    sort(v.begin(), v.end(), op);

    int result = 1;
    int endTime = v[0].second;

    for (int i=1; i<N; i++) {
        if (v[i].first < endTime) continue;

        endTime = v[i].second;
        result++;
    }

    cout<<result;
}