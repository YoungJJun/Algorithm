#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N,jump,slide,hp,K;
    //N열
    //Jump, Slide, Hp
    //장애물에 부딛히면 Hp 감소량 K


    //변수 값 입력
    cin>>N>>jump>>slide>>hp>>K;


    //장애물 입력
    vector<vector<char>> input(3,vector<char>(N,0));
    for (int i=0; i<3; i++) {
        for (int j=0; j<N; j++) {
            cin>>input[i][j];
        }
    }

    //장애물 변환
    vector<int> v(N); int jj=0; int j=0; int s=0;
    for (int i=0; i<N; i++) {
        if (input[0][i]=='.' && input[1][i]=='^' && input[2][i]=='^') {
            v[i]=2;
            jj++;
        }
        else if (input[0][i]=='v' && input[1][i]=='v' && input[2][i]=='.') {
            v[i]=-1;
            s++;
        }
        else if (input[0][i]=='.' && input[1][i]=='.' && input[2][i]=='^'){
            v[i]=1;
            j++;
        }
    }


    //j:1단점프 필요 장애물 수
    //jj:2단점프 필요 장애물 수
    //s:슬라이딩 필요 장애물 수


    //슬라이딩은 우선 처리
    while (s && slide) {
        s--;
        slide--;
    }
    //1단 점프 먼저 처리 greedy
    while (j && jump) {
        j--;
        jump--;
    }
    //2단 점프 처리
    while (jj && jump/2>=1) {
        jj--;
        jump-=2;
    }

    hp = hp - (s+j+jj)*K;
    if (hp>0) {
        cout<<hp;
    }
    else {
        cout<<-1;
    }




}