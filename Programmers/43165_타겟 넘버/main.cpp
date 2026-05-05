#include <string>
#include <vector>

using namespace std;

void DFS(int sum, int i, vector<int> &numbers, int &ans, int tar){
    if(i==numbers.size()){
        if(sum==tar) ans++;
        return;
    }

    DFS(sum+numbers[i], i+1, numbers, ans, tar);
    DFS(sum-numbers[i], i+1, numbers, ans, tar);

}

int solution(vector<int> numbers, int target) {

    int ans=0;
    DFS(0, 0, numbers, ans, target);
    return ans;
}