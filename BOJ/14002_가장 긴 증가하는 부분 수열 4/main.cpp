#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> input(n);
    vector<int> dp(n);
    vector<int> nums;

    for (int i = 0; i < n; i++) {
        cin >> input[i];

        if (nums.empty() || nums.back() < input[i]) {
            nums.push_back(input[i]);
            dp[i] = nums.size()-1;
            continue;
        }

        auto it = lower_bound(nums.begin(), nums.end(), input[i]);
        *it = input[i];
        dp[i] = it - nums.begin();
    }


    int target = nums.size() - 1;
    stack<int> st;
    for (int i = n-1; i >= 0; i--) {
        if (dp[i] == target) {
            st.push(input[i]);
            target--;
        }
    }

    cout<<nums.size()<<"\n";
    while (!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
}