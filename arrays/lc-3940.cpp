// LC-3940 : Limit Occurance in sorted array
// You are given a sorted integer array nums and an integer k.
// Return an array such that each distinct element appears at most k times, while preserving the relative order of the elements in nums.
// Note: If a distinct element appears at least k times, then it must appear exactly k times in the resulting array.

#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        
        if(nums.empty()) return {}; // when the input nums is empty - but the constrains tell it will never be empty

        vector<int> ans = {};
        int count = 1;
        ans.push_back(nums[0]); // push the first element as k>0
 
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){// if current element is same as prev
                // and count is less then k - then insert in the ans
                if(count<k){
                    ans.push_back(nums[i]);
                    count++;
                }
            }else{ // when nums[i] != nums[i-1] - means new element encountered
                // so add the new element to the ans and reset the counter back to 1
                ans.push_back(nums[i]);
                count = 1;
            }
        }
        return ans;
    }

    vector<int> limitOccurances2(vector<int>& nums, int k){
        int n = nums.size();
        vector<int> ans = {};
        int i=0;

        while(i<n){
            int j = i; // j will be used to count occurance of same element

            while( j<n && nums[j] == nums[i]){
                j++; // so j counts how many times 
            }

            // we break out of the above loop as j reaches a point where the new element appears
            int least = min(k, i-j);
            for(int p=0; p<least; p++){
                ans.push_back(nums[i]); // the element is pushed k or i-k times
            }

            i = j; // move i to j's current value - the value from where new element starts 
        }
        return ans;
    }
};