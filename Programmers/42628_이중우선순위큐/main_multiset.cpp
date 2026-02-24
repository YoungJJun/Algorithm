#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> set;

    for(auto s : operations){
        char cmd = s[0];
        int val = stoi(s.substr(2));

        if(cmd == 'I'){
            set.insert(val);
        }
        else if(cmd == 'D' && !set.empty()){
            if(val == 1 ){
                //최댓값 삭제
                set.erase(prev(set.end()));
            }
            else if(val == -1){
                //최솟값 삭제
                set.erase(set.begin());
            }
        }
    }

    vector<int> result;
    if(set.empty()){
        result.push_back(0);
        result.push_back(0);
    }
    else{
        result.push_back(*set.rbegin());
        result.push_back(*set.begin());
    }
    return result;
}