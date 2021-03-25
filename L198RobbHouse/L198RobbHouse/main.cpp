//
//  main.cpp
//  L198RobbHouse
//
//  Created by HAO LI on 3/25/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int rob(vector<int>& nums){
        if(nums.size() <= 1){
            return nums.empty()? 0: nums[0];
        }
        vector<int> dp = {nums[0], max(nums[0], nums[1])};
        for(int i = 2; i < nums.size(); i++){
            dp.push_back(max((nums[i] + dp[i-2]), dp[i-1]));
        }
        return dp.back();
    }
};
int main(int argc, const char * argv[]) {
    Solution solu;
    vector<int> input1 = {1, 2, 3, 1};
    cout<< "Max total value to rob:" << solu.rob(input1)<< endl;
    vector<int> input2 = {2,7,9,3,1};
    cout<< "Max total value to rob:" << solu.rob(input2)<< endl;
}
