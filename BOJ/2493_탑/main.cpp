#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> result(N+1);
    stack<pair<int, int>> st;

    for (int i = 1; i <= N; i++) {
        int input;
        cin >> input;

        while (!st.empty() && st.top().first < input) {
            st.pop();
        }

        if (st.empty()) {
            result[i] = 0;
        }
        else {
            result[i] = st.top().second;
        }

        st.push(make_pair(input, i));
    }

    for (int i=1; i<=N; i++) {
        cout << result[i] << " ";
    }
}