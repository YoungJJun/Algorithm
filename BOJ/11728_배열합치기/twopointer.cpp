#include <iostream>
#include <vector>
using namespace std;
//BOJ 11728
//투포인터 개념학습
int main() {
    int N,M;
    cin>>N>>M;

    vector<int> A(N);
    vector<int> B(M);
    for(int i=0;i<N;i++) {
        cin>>A[i];
    }
    for(int i=0;i<M;i++) {
        cin>>B[i];
    }

    int As=0,Bs=0;


    vector<int> result;
    if (A[0]<B[0]) {
        result.push_back(A[0]);
        As++;
    }
    else {
        result.push_back(B[0]);
        Bs++;
    }

    while (result.size()!= N+M) {
        if (As==N) {
            result.push_back(B[Bs]);
            Bs++;
            continue;
        }
        if (Bs==M) {
            result.push_back(A[As]);
            As++;
            continue;
        }

        if (A[As] < B[Bs]) {
            result.push_back(A[As]);
            As++;
        }
        else {
            result.push_back(B[Bs]);
            Bs++;
        }
    }

    for (int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }

}