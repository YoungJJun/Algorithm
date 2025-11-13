#include <iostream>
#include <vector>
using namespace std;
int N,M;
int x,y;
int K;

class Dice {
public :

    int d1,d2,d3,d4,d5,d6;

    Dice() {
        d1=d2=d3=d4=d5=d6=0;
    }

    void rollE() {

        int tmp=d6;
        d6=d3;
        d3=d1;
        d1=d4;
        d4=tmp;
    }
    void rollW() {

        int tmp =d6;
        d6=d4;
        d4=d1;
        d1=d3;
        d3=tmp;
    }
    void rollN() {

        int tmp =d6;
        d6=d2;
        d2=d1;
        d1=d5;
        d5=tmp;
    }
    void rollS() {

        int tmp =d6;
        d6=d5;
        d5=d1;
        d1=d2;
        d2=tmp;
    }

private:
};

int main() {

    cin>>N>>M;

    cin>>y>>x;

    cin>>K;


    vector<vector<int>> v(N,vector<int>(M)); //N*M matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin>>v[i][j];
        }
    }


    int cmd;
    Dice d = Dice();
    while (K--) {

        cin>>cmd;
        if (K==6) {

        }
        if (cmd==1) {
            //E
            if (x+1 > M-1) {//굴릴 수 없는 상황

            }
            else {
                d.rollE();
                x++;
                if (v[y][x]==0) {
                    v[y][x]=d.d6;
                }
                else {
                    d.d6=v[y][x];
                    v[y][x]=0;
                }
                cout<<d.d1<<endl;
            }
        }
        else if (cmd==2) {
            //W
            if (x-1 < 0) {//굴릴 수 없는 상황

            }
            else {
                d.rollW();
                x--;
                if (v[y][x]==0) {
                    v[y][x]=d.d6;
                }
                else {
                    d.d6=v[y][x];
                    v[y][x]=0;
                }
                cout<<d.d1<<endl;
            }
        }
        else if (cmd==3) {
            //N
            if (y-1 < 0) {//굴릴 수 없는 상황

            }
            else {
                d.rollN();
                y--;
                if (v[y][x]==0) {
                    v[y][x]=d.d6;
                }
                else {
                    d.d6=v[y][x];
                    v[y][x]=0;
                }
                cout<<d.d1<<endl;
            }
        }
        else if (cmd==4) {
            //S
            if (y+1 > N-1) {//굴릴 수 없는 상황

            }
            else {
                d.rollS();
                y++;
                if (v[y][x]==0) {
                    v[y][x]=d.d6;
                }
                else {
                    d.d6=v[y][x];
                    v[y][x]=0;
                }
                cout<<d.d1<<endl;

            }
        }

    }

}