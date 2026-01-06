#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {

    queue<int> q;
    priority_queue<int> pq;

    //중복 값 고려해서 q에 들어갈 수 없는 값인 -1을 삽입함
    //따라서 우선순위를 따로 저장
    int targetPrio = priorities[location];

    //현재까지 실행된 수
    int finished = 0;


    //우선순위를 모두 q에 삽입, pq에 삽입
    //목표로 하는 값은 -1로 삽입해서 구분
    for(int i=0; i<priorities.size(); i++){
        if(i==location){
            q.push(-1);
        }
        else{
            q.push(priorities[i]);
        }
        pq.push(priorities[i]);
    }





    while(1){
        int curPrio = q.front(); q.pop();

        //목표 값 관련 로직
        if(curPrio==-1){
            if(pq.top() <= targetPrio){
                break;
            }
            else{
                q.push(-1);
                continue;
            }
        }


        //일반 로직
        if(pq.top() <= curPrio){
            pq.pop();
            finished++;
        }
        else{
            q.push(curPrio);
        }

    }


    return finished+1;
}