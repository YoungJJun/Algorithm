#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct truck{
    int weight; //트럭무게
    int length; //다리 얼마나 건넜는지
};
int solution(int bridge_length, int weight, vector<int> truck_weights) {

    //q는 아직 다리에 진입하지 않은 트럭 정보
    queue<truck> q;
    for(auto x : truck_weights){
        truck t;
        t.weight = x;
        t.length = bridge_length;
        q.push(t);
    }

    //ing는 현재 건너는 중인 트럭 정보
    queue<truck> ing;
    int n = truck_weights.size();
    int time = 1;
    int finished = 0;
    int curWeight = 0;
    while(finished != n){

        //건너지 않은 트럭이 무게조건 통과시 다리로 진입
        if(!q.empty() && curWeight+q.front().weight <= weight){
            ing.push(q.front());
            curWeight += q.front().weight;
            q.pop();
        }

        //모든 다리에 있는 트럭 1씩 진행 (length--)
        int tmp = ing.size();
        while(tmp--){
            ing.front().length--;
            ing.push(ing.front());
            ing.pop();
        }

        //다리를 건너간 트럭 ing에서 제거하고 건너간 트럭의 수 카운트
        while(!ing.empty() && ing.front().length == 0){
            finished++;
            curWeight -= ing.front().weight;
            ing.pop();
        }

        //시간++
        time++;
    }

    return time;

}