//
//  main.cpp
//  L256PaintHouse
//
//  Created by HAO LI on 3/26/21.
//

#include <iostream>
#include <sstream>

using namespace std;

class Solution{
public:
    int my_solution(int n){
        
        stringstream ss;
        ss << n;
        string s;
        ss >> s;
        
        cout << s << endl;
        cout << s[0] << endl;
        
        if(s.length() == 1){
            s[0] = '0';
        }else{
            for(int i = 1; i < s.length(); i++){
                s[i] = '0';
            }
        }
        
        
        cout << "test: " << s << endl;
        
        int res = stoi(s);
        cout << res << endl;
        return 0;
        
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    s.my_solution(15);
    s.my_solution(9);
    return 0;
}
