//
//  main.cpp
//  L215KthLargestElem
//
//  Created by HAO LI on 3/25/21.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int fidnKthLargest(vector<int>&nums, int k){
        int left = 0, right = nums.size() - 1;
        // loop to partition the array iteratively to compare the pivot with the target position
        while(true){
            int pos = partition(nums, left, right);
            
            // pivot meeting the requirements
            if(pos == k -1)
                return nums[pos];
            
            // pivot greater than Kth position
            else if(pos > k -1){
                right = pos - 1;
            }
            
            // pivot less than Kth position
            else
                left = pos + 1;
        }
        
    }
    
    /**
            main logic for the quick sort render the vector into two section where left portion greater than righter portion between the pivot
     */
    int partition(vector<int>&nums, int left, int right){
        int pivot = nums[left], l = left + 1, r = right;
        while(l <= r){
            // elem on the left smaller than pivot and elem on the right greater than the pivot: swap them if satisfied this condition
            if(nums[l] < pivot && nums[r] > pivot){
                swap(nums[l++], nums[r--]);
            }
            
            // if either of them not meeting the above condition
            if(nums[l] >= pivot) l++;
            if(nums[r] <= pivot) r--;
            
            // at last l == r but nums[l] still smaller than pivot, simply r--
        }
        
        // swap the pivot with the element which immediately before the first element that is less than the pivot
        swap(nums[left], nums[r]);
        return r;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> input = {3, 2, 1, 5, 6, 4,};
    int k = 2;
    Solution s;
    cout <<"The "<<k <<"th largest element is: " << s.fidnKthLargest(input, 2) << endl;
}
