#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> high;
    priority_queue<int, vector<int>, greater<>> low;
    unordered_map<int,int> map;

    for(int i=0; i<operations.size(); i++){
        char cmd = operations[i][0];
        int value = stoi(operations[i].substr(2, operations[i].size()-2));

        if(cmd == 'I'){
            high.push(value);
            low.push(value);
            map[value]++;
        }

        if(cmd == 'D' && value == -1){

            while(!low.empty() && map[low.top()] < 1){
                low.pop();
            }

            if(!low.empty()){
                map[low.top()]--;
                low.pop();
            }
        }

        if(cmd == 'D' && value == 1){


            while(!high.empty() && map[high.top()] < 1){
                high.pop();
            }

            if(!high.empty()){
                map[high.top()]--;
                high.pop();
            }
        }
    }

    while(!low.empty() && map[low.top()] < 1){
        low.pop();
    }
    while(!high.empty() && map[high.top()] < 1){
        high.pop();
    }

    vector<int> result;
    if(high.empty() && low.empty()){
        result.push_back(0);
        result.push_back(0);
    }
    else{
        result.push_back(high.top());
        result.push_back(low.top());
    }
    return result;
}