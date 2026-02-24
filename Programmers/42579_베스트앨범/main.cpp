#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

unordered_map<string, int> genreCnt;

int min (int a, int b){
    if(a<b) return a;
    return b;
}

bool genreComp(string a, string b){
    if(genreCnt[a] < genreCnt[b]){
        return false;
    }
    return true;
}

bool musicComp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second != p2.second){
        if(p1.second > p2.second) return true;
        return false;
    }

    if(p1.first < p2.first) {
        return true;
    }
    return false;

}

vector<int> solution(vector<string> genres, vector<int> plays) {

    unordered_map<string, vector<pair<int,int>>> genreMusicList;
    vector<string> genreList;
    vector<int> result;

    for(int i=0; i<genres.size(); i++){
        if(genreCnt.find(genres[i]) == genreCnt.end()){
            genreList.push_back(genres[i]);
        }

        genreCnt[genres[i]] += plays[i];
        genreMusicList[genres[i]].emplace_back(i, plays[i]);
    }


    sort(genreList.begin(), genreList.end(), genreComp);

    for(int i=0; i<genreList.size(); i++){
        sort(genreMusicList[genreList[i]].begin(), genreMusicList[genreList[i]].end(), musicComp);

        for(int j=0; j<min(2, genreMusicList[genreList[i]].size()); j++){
            result.push_back(genreMusicList[genreList[i]][j].first);
        }
    }




    return result;
}