//
//  main.cpp
//  L169MajorityElement
//
//  Created by HAO LI on 3/25/21.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int majorityElement(vector<int>& nums){
        int res = 0;
        int n = static_cast<int>(nums.size());
        for(int i = 0; i < 32; i++){
            int ones = 0, zeros = 0;
            for (int num: nums ) {
                if(ones > n/2 || zeros > n/2){
                    break;
                }
                if((num & (1 << i)) != 0 ) ones++;
                else zeros++;
            }
            if(ones > zeros){
                res |= (1 << i);
            }
        }
        return res;
    }
    
    int method2(vector<int>& nums){
        int res = 0, cnt = 0;
        for(int num: nums){
            if(cnt == 0){
                res = num;
                cnt++;
            }
            else{
                if(num == res){
                    cnt++;
                }else
                    cnt--;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    vector<int>input = {3, 2, 3};
    Solution s;
    cout << "bit manipulation: "<<s.majorityElement(input) << endl;;
    
    cout << "Moore's voting method result: " << s.method2(input) << endl;;
}
