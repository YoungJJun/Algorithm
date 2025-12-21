#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool op(string s1, string s2){
    return s1.size()<s2.size();
}
bool solution(vector<string> phone_book) {
    bool result = true;
    unordered_map<string, int> map;
    sort(phone_book.begin(),phone_book.end(),op);


    for(string s : phone_book){

        for(int i=1; i<s.size(); i++){
            string ss = s.substr(0,i);
            if(map.find(ss)!=map.end()){
                result=false;
                break;
            }

        }

        if(result==false) break;
        else{
            map[s]=1;
        }


    }
    return result;

}