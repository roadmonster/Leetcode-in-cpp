//
//  main.cpp
//  L973
//
//  Created by HAO LI on 3/21/21.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    vector<vector<int>> kClosest(vector<vector<int>>&points, int k){
        vector<vector<int>>res;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < points.size(); i++){
            int t = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({t, i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            res.push_back(points[t.second]);
        }
        return res;
    }
    
    void printSolution(vector<vector<int>>solution){
        for(int i = 0; i < solution.size(); i++){
            cout << "x: " << solution[i][0] << " y:" << solution[i][1] << endl;
        }
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> input{{1, 3}, {-2, 2}};
    Solution s;
    s.printSolution(s.kClosest(input, 1));
}
