//
//  main.cpp
//  L395LongestSubstringK
//
//  Created by HAO LI on 3/25/21.
//

#include <iostream>

using namespace std;
class Solution{
public:
    int longestSubstringK(string s, int k){
        // initialize array of 26 spots to remember each letter frequency
        int m[26] = {0};
        int n = s.size();
        
        cout << "n: " << n << endl;
        
        //step through each letter of the string and note down their frequency
        for(int i = 0; i < n; i++){
            m[s[i] - 'a']++;
        }
        
//        for(int i = 0; i < 26; i++){
//            cout << "current letter index: " << i << ", freq: " << m[i] << endl;
//        }
        
        // create a bool value to tell if this whole string is meeting the requirement
        bool ok = true;
        
        // variable to hold the max length
        int res = 0;
        
        // index to hold the start of substr
        int maxIdx = 0;
        
        for(int i = 0; i < n; i++){
            if(m[s[i] - 'a'] < k){
                
                ok = false;
                
                // find the longest substring from the maxIdx to index before current idx
                res = max(res, longestSubstringK(s.substr(maxIdx, i - maxIdx), k));
                cout << "res:" << res << endl;
                
                // the substr to previous letter has been done, move on to next substr
                maxIdx = i + 1;
            }
            
            
        }
        
        if(ok){
            return n;
        }
        else{
            // need to recursively check the substr from maxIdx to n-1
            return max(res, longestSubstringK(s.substr(maxIdx, n - maxIdx), k));
        }
        
        
        
        
        return 0;
    };
};
int main() {
    string s = "abbac";
    int k = 2;
    Solution solu;
    int res = solu.longestSubstringK(s, k);
    cout << "Restult: " << res << endl;;
    return 0;
}
