#include <iostream>
#include <deque>
#include <vector>
using namespace std;


constexpr int INF = 1e8;
int N,K;

int main() {

    vector<int> dist(100001, INF);

    cin>>N>>K;
    deque<int> deq;
    dist[N]=0;
    deq.push_back(N);

    while(!deq.empty()) {

        int cur = deq.front(); deq.pop_front();
        if (cur==K) break;

        //순간이동
        if (cur*2<=100000 && dist[cur*2] > dist[cur]) {
            dist[cur*2] = dist[cur];
            deq.push_front(cur*2);
        }
        //한칸 이동
        if (cur-1>=0 && dist[cur-1] > dist[cur] + 1) {
            dist[cur-1] = dist[cur] + 1;
            deq.push_back(cur-1);
        }
        if (cur+1<=100000 && dist[cur+1] > dist[cur] + 1) {
            dist[cur+1] = dist[cur] + 1;
            deq.push_back(cur+1);
        }

    }

    cout<<dist[K]<<endl;

}