#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());
    int i = 0;
    int j = people.size()-1;

    while(i<=j){
        if(i==j){
            answer++;
            break;
        }

        if(people[i]+people[j]<=limit){
            answer++;
            i++;
            j--;
        }
        else{
            answer++;
            j--;
        }
    }


    return answer;
}