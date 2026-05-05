#include <string>
#include <vector>
#include <iostream>

using namespace std;

void floyd(vector<vector<int>> & g){
    int n= g.size()-1;
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(g[i][k]==1 && g[k][j]==1){
                    g[i][j] = 1;
                }
            }
        }
    }
}


int solution(int n, vector<vector<int>> results) {

    vector<vector<int>> win (n+1, vector<int>(n+1, 0));
    vector<vector<int>> lose (n+1, vector<int>(n+1, 0));

    for(auto p : results){
        int a = p[0];
        int b = p[1];

        win[a][b] = 1;
        lose[b][a] = 1;
    }

    floyd(win);
    floyd(lose);

    /*
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<win[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<lose[i][j]<<" ";
        }
        cout<<endl;
    }
    */



    int ans=0;
    for(int i=1; i<=n; i++){
        int count=0;
        for(int j=1; j<=n; j++){
            if(win[i][j]==1 || lose[i][j]==1){
                count++;
            }
        }

        if(count==n-1) {ans++;}
    }

    return ans;
}

