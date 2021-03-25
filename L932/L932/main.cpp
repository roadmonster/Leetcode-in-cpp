//
//  main.cpp
//  L932
//
//  Created by HAO LI on 3/21/21.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int>beautifulArray(int N){
        vector<int>res{1};
        while(res.size()< N){
            vector<int>temp;
            for(int num: res){
                if(num * 2 - 1 < N){
                    temp.push_back(num * 2 -1);
                }
            }
            
            for(int num: res){
                if(num * 2 <= N){
                    temp.push_back(num * 2);
                }
            }
            
            
            res = temp;
        }
        return res;
    }
    
    void printSolution(vector<int>solution){
        for(int num: solution){
            cout << num <<" ";
        }
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.printSolution(s.beautifulArray(4));
}
