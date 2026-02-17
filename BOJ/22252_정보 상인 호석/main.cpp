#include <iostream>
#include <map>
#include <queue>
using namespace std;
int Q;

int main() {

    long long value = 0;

    cin >> Q;
    int cmd, n, input;
    string name;
    queue<int> inputQ;

    map<string, priority_queue<int>> map;

    while (Q--) {

        cin >> cmd >> name >> n;

        // 정보 입력
        if ( cmd == 1) {

            // 입력받기
            for (int i=0; i<n; i++) {
                cin >> input;
                inputQ.push(input);
            }

            // 없으면 생성 후 삽입, 있으면 삽입
            if (map.find(name) == map.end()) {
                map[name] = priority_queue<int>();
            }
            while (!inputQ.empty()) {
                map[name].push(inputQ.front());
                inputQ.pop();
            }
        }

        // 정보 구매
        else if ( cmd == 2) {
            for (int i=0; i<n; i++) {
                if (map[name].empty()) break;
                value += map[name].top();
                map[name].pop();
            }
        }

    }

    cout << value;

}