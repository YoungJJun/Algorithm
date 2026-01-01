#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map <int, int> map;
    int type = 0;
    for( auto x : nums){
        if(map.find(x)==map.end()){
            map[x] = 1;
            type++;
        }
        else{
            map[x] += 1;
        }
    }

    int select = nums.size() / 2;
    if(type > select){
        return select;
    }
    else{
        return type;
    }

}