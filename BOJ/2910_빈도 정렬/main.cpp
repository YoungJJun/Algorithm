#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<int, int> freq;
unordered_map<int, int> pos;

bool op(int a, int b) {

    int freqA = freq[a];
    int freqB = freq[b];

    if (freqA != freqB) return freqA > freqB;

    int posA = pos[a];
    int posB = pos[b];

    return posA < posB;
}

int main() {
    int N, C;
    cin >> N >> C;

    vector<int> v (N);

    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        v[i] = input;

        if (freq.find(input) == freq.end()) {
            freq[input] = 1;
        }
        else {
            freq[input]++;
        }

        if (pos.find(input) == pos.end()) {
            pos[input] = i;
        }
    }

    sort(v.begin(), v.end(), op);

    for (auto x : v) {
        cout << x << " ";
    }

}