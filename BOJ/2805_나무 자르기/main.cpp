#include <iostream>
#include <vector>
using namespace std;

int main() {

    int N, M;
    cin >> N >> M;
    vector<int> trees(N);
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }


    long long sum = 0;
    int start = 0, end = 2000000000;
    long long result = 2000000000;

    while (start <= end) {
        int mid = (start + end) / 2;

        //cut을 가지고 sum 계산
        sum=0;
        for (auto x : trees) {
            if (x <= mid) continue;
            sum += x-mid;
        }


        if ( sum > M) {
            //cut을 증가
            start = mid + 1;
            result = mid;
        }
        else if (sum < M) {
            //cut을 감소
            end = mid - 1;
        }
        else {
            result = mid;
            break;
        }

    }

    cout << result << endl;



}