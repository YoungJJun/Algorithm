#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int input;
    vector<int> nums;

    for (int i=0; i<n; i++) {
        cin >> input;

        if (nums.empty() || nums.back() < input) {
            nums.push_back(input);
            continue;
        }
        auto it = lower_bound(nums.begin(), nums.end(), input);
        *it = input;
    }

    cout<<nums.size();
}