#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

    int N,M;
    cin>>N>>M;

    //1~N을 오름차순 저장
    vector<int> v(N+1);
    for (int i=1; i<=N; i++) {
        v[i]=i;
    }

    //0,1을 이용해 조합 생성을 위한 벡터 생성
    vector<int> select;
    for (int i=1; i<=M; i++) {
        select.push_back(1);
    }
    for (int i=1; i<=N-M; i++) {
        select.push_back(0);
    }


    //prev_permutation을 select에 대해 수행
    //각 select에 맞게 출력
    do {

        for (int i=0; i<N; i++) {
            if (select[i]==1) {
                cout<<v[i+1]<<" ";
            }
        }
        cout<<endl;
    }while (prev_permutation(select.begin(), select.end()));
}