#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    unordered_map<string, int> map;
    int loc=-1;

    map[words[0]]=1;
    for(int i=1; i<words.size(); i++){

        string cur_word = words[i];
        string bef_word = words[i-1];

        if(map.find(cur_word) != map.end()
           || cur_word[0] != bef_word[bef_word.size()-1]){
            loc=i;
            break;
        }
        else{
            map[cur_word]=1;
        }

    }

    if(loc==-1){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back((loc%n)+1);
        answer.push_back((loc/n)+1);
    }

    return answer;
}