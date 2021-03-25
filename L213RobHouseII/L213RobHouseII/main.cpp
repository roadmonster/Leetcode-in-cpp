//
//  main.cpp
//  L213RobHouseII
//
//  Created by HAO LI on 3/25/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    
    int robII(vector<int>& nums){
        // if nums length is less than 1 return 0 or first element
        if(nums.size()<= 1){
            return nums.empty()? 0: nums[0];
        }
        
        // return the maximum of the two cases rob the last one or not to rob the last one
        return max(rob(nums, 0, nums.size()-1), rob(nums, 1, nums.size()));
    }
    
    /**
     takes the array and the left as the first house to rob, and the right as the last house that could be robbed
     */
    int rob(vector<int>& nums, int left, int right ){
        // if the first house and the last house could be robbed are next to each other,
        //meaning there could be only 3 houses available, hence only one could be robbed,
        //simply return the first one, since the other case also return its first one which the next house.
        if(right - left <= 1){
            return nums[left];
        }
        
        // build the dp array of size nums.size()-1 or nums.size()
        // it does not matter because we simply start the array from left + 2
        // where the first element is always dp[left] hence shall not have any nullptr issue
        vector<int>dp(right, 0);
        dp[left] = nums[left];
        dp[left + 1] = max(nums[left], nums[left + 1]);
        for(int i = left + 2; i < right; i++){
            dp[i] = max((nums[i] + dp[i-2]), dp[i-1]);
        }
        
        return dp.back();
    }
};

int main(int argc, const char * argv[]) {
    vector<int> input1 = {1, 3, 4, 1};
    Solution s;
    cout << s.robII(input1) << endl;
    
}
