#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int cnt = 0;
    int value = 666;
    while (cnt != n) {
        string s = to_string(value);

        if (s.find("666") != string::npos) {
            cnt++;
        }

        value++;
    }

    cout << value-1 << endl;
}