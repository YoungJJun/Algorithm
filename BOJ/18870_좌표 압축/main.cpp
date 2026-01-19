#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int,int>> v(N);
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v[i] = make_pair(tmp, i);
    }
    sort(v.begin(), v.end());

    vector<int> ans(N);
    int smaller = 0;
    for (int i=0; i<N; i++) {

        if (i==0) {
            ans[v[i].second] = smaller;
            continue;
        }


        if (v[i].first > v[i-1].first) {
            smaller++;
            ans[v[i].second] = smaller;
        }
        else {
            //같은경우
            ans[v[i].second] = smaller;
        }
    }

    for (auto x : ans) {
        cout<<x<<" ";
    }
}