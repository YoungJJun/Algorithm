#include <iostream>
#include <vector>
using namespace std;
int min(int a,int b,int c) {
    int m=a;
    if (m>b) m =b;
    if (m>c) m=c;
    return m;
}

int main() {
    int N;
    cin>>N;
    vector<int> from(N);
    vector<int> to(N);

    int to1=0, from1=0;
    for (int i=0; i<N; i++) {
        cin>>from[i];
        from1+=from[i];
    }
    for (int i=0; i<N; i++) {
        cin>>to[i];
        to1+=to[i];
    }

    int cntZeroToOne=0;
    int cntOneToZero=0;
    for (int i=0; i<N; i++) {
        if (from[i]==0 && to[i]==1) {
            cntZeroToOne++;
        }
        else if (from[i]==1 && to[i]==0) {
            cntOneToZero++;
        }
        else {

        }
    }

    //토글로만
    int a = cntZeroToOne + cntOneToZero;

    //전체 해제 후 1로 만들기
    int b;
    if (from1 == 0) b=0; //이미 0이면 0으로 시작
    else if (from1 == 1) b=1; //1개만 1이면 토글 1회 후 시작
    else if (from1==N) b=1; //모두 1이면 해제 1회 후 시작
    else b=2; //섞여있으면 전체체크, 전체해제 = 2
    b = b+to1;

    //전체 체크 후 0으로 만들기
    int c;
    if (from1 == N) c=0;
    else c=1;
    c = c+N-to1;

    cout<<min(a,b,c);
}
