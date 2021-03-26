//
//  main.cpp
//  L254FactorCombinations
//
//  Created by HAO LI on 3/26/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> getFactors(int n){
        vector<vector<int>>res;
        helper(n, 2, {}, res);
        return res;
    }
    
    /**
        n==1 stops the recursion since  1 is not regarded as a factor and each recursion the target
     get divided by i ( n/ i) if the target becomes 1 then there is no more further division of factors
     */
    void helper(int n, int start, vector<int>out, vector<vector<int>>& res){
        
        // if n == 1 then if out array is more than one then we can push out into res
        if(n == 1){
            if(out.size() > 1){
                res.push_back(out);
            }
            return;
        }
        
        // loop to put all the factors into out array for each available factor
        // further recurse it into the next level until return
        // then pop back this factor try another one
        for(int i = start; i <= n; i++){
            if(n % i != 0)
                continue;
            out.push_back(i);
            helper(n/i, i, out, res);
            out.pop_back();
        }
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> result = s.getFactors(8);
    
    for(int i = 0; i < result.size(); i++){
        
        for (int j = 0; j < result[i].size(); j++) {
            cout <<result[i][j] <<" ";
        }
        cout << "\n";
    }
}
