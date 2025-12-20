#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> p;
    for(string tmp : participant){
        if(p.find(tmp)!=p.end()){
            p[tmp]=p[tmp]+1;
        }
        else{
            p[tmp]=1;
        }
    }

    for(string tmp : completion){
        p[tmp]=p[tmp]-1;
    }

    for(string tmp : participant){
        if(p[tmp]==1) return tmp;
    }


}