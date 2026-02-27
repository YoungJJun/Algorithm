#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int N;
    int result = 0;
    cin >> N;

    vector<pair<int, int>> v;
    priority_queue<int, vector<int>, greater<>> endTime;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.emplace_back(a,b);
    }

    sort(v.begin(), v.end());

    for (int i=0; i<v.size(); i++) {

        if (endTime.empty() || endTime.top() > v[i].first) {
            endTime.push(v[i].second);
            result++;
            continue;
        }

        endTime.pop();
        endTime.push(v[i].second);
    }

    cout << result << endl;

}