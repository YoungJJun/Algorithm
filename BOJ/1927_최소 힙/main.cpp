#include <iostream>
#include <queue>
using namespace std;


int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 0; i < N; i++) {
        int x;;
        cin >> x;

        if (x == 0) {
            if (!pq.empty()) {
                cout<< pq.top() << "\n";
                pq.pop();
            }
            else {
                cout << 0 << "\n";
            }
        }
        else {
            pq.push(x);
        }
    }


}