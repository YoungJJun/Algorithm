#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
struct task{
    int duration;
    int reqNum;
    int taskNum;
};

bool reqTimeSort(task &t1, task &t2){
    return t1.reqNum < t2.reqNum;
}

struct pqSort{
    bool operator()(task &t1, task &t2){
        if(t1.duration != t2.duration) return t1.duration > t2.duration;

        if(t1.reqNum != t2.reqNum) return t1.reqNum > t2.reqNum;

        return t1.taskNum > t2.taskNum;
    }
};

int solution(vector<vector<int>> jobs) {

    int n = jobs.size();
    vector<task> tasks;

    for(int i = 0; i<n; i++){
        task t;
        t.duration = jobs[i][1];
        t.reqNum = jobs[i][0];
        t.taskNum = i;
        tasks.push_back(t);
    }
    sort(tasks.rbegin(), tasks.rend(), reqTimeSort);


    int finishCnt = 0;
    int time = 0;
    int result = 0;
    priority_queue<task, vector<task>, pqSort> pq;
    while(finishCnt != n){

        while(tasks.size()!=0 && tasks[tasks.size()-1].reqNum <= time){
            pq.push(tasks[tasks.size()-1]);
            tasks.pop_back();
        }

        if(pq.empty()){
            time++;
            continue;
        }

        result += time + pq.top().duration - pq.top().reqNum;
        time += pq.top().duration;
        pq.pop();
        finishCnt++;
    }

    return result/n;
}