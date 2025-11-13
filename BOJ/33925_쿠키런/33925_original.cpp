#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N,jump,slide,hp,K;
    //N열 즉 장애물 수
    //Jump, Slide, Hp
    //장애물에 부딛히면 Hp -= K


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
        if (input[0][i]=='.' && input[1][i]== '.' && input[2][i]=='.') {
            v[i]=0;
        }
        else if (input[0][i]=='.' && input[1][i]=='^' && input[2][i]=='^') {
            v[i]=2;
            jj++;
        }
        else if (input[0][i]=='v' && input[1][i]=='v' && input[2][i]=='.') {
            v[i]=-1;
            s++;
        }
        else {
            v[i]=1;
            j++;
        }
    }


    //j:1단점프 장애물 수
    //jj:2단점프 장애물 수
    //s:슬라이딩 장애물 수

    //슬라이딩은 우선 처리
    if (slide < s) {
        hp -= (s-slide)*K;
    }


    if (hp<=0) cout<<-1;
    else {

        //장애물이 최적으로 깔려있어서 최선의 상황에서 수행한다고 치면
        if (j<=jump) jump= jump-j;
        else {
            hp -= (j-jump)*K;
            jump=0;
        }

        if (hp<=0) cout<<-1;
        else {

            if (jj*2 <=jump) {

            }
            else {
                hp -= (jj-jump/2)*K;
            }

            if (hp<=0) cout<<-1;
            else {
                cout<<hp;
            }
        }




    }





}