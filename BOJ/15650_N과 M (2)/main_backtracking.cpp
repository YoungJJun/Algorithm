#include <iostream>
#include <vector>
using namespace std;

void comb(int start, vector<int> &v, int max, int n) {

    if (v.size() == max) {
        for (auto x : v) {
            cout<<x<<" ";
        }
        cout<<"\n";
        return;
    }

    for (int i=start; i<=n; i++) {
        v.push_back(i);
        comb(i+1, v, max, n);
        v.pop_back();
    }
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<int> v;
    comb(1, v, m, n);
}