#include <iostream>
#include <vector>
using namespace std;
int n,m;
void comb(vector<int> &v) {

    if (v.size() == m) {
        for (auto x : v) {
            cout<< x <<" ";
        }
        cout<<"\n";
        return;
    }

    for (int i = 1; i<=n; i++) {
        v.push_back(i);
        comb(v);
        v.pop_back();
    }
}

int main() {

    cin >> n >> m;

    vector<int> v;
    comb(v);
}