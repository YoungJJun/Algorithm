#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int dist(pair<int, int> &p1, pair<int, int> &p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {

    cin >> N >> M;

    vector<pair<int, int>> chicken;
    vector<pair<int, int>> house;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                house.push_back(make_pair(i, j));
            }
            else if (x == 2) {
                chicken.push_back(make_pair(i, j));
            }
        }
    }


    int minChickenDist = 1e8;
    vector<int> select;
    for (int i = 0; i < chicken.size() - M ; i++) select.push_back(0);
    for (int i = 0; i < M; i++) select.push_back(1);
    do {
        int chickenDist = 0;
        for (int i = 0; i < house.size(); i++){
            auto curHouse = house[i];

            int tmpMin = 1e8;
            for (int j = 0; j < chicken.size(); j++) {
                if (select[j] != 1) continue;

                auto curChicken = chicken[j];
                tmpMin = min(tmpMin, dist(curHouse, curChicken));
            }
            chickenDist += tmpMin;
        }

        minChickenDist = min(minChickenDist, chickenDist);

    }while (next_permutation(select.begin(), select.end()));

    cout<<minChickenDist<<endl;

}