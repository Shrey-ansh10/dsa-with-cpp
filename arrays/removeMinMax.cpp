// LC-2091 : Removing Minimum and Maximum From Array
// You are given a 0-indexed array of distinct integers nums.

// -> There is an element in nums that has the lowest value and an element that has the highest value. 
// We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.
// -> A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.
// Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.

// Constraints:
    // 1 <= nums.length <= 10^5
    // -10^5 <= nums[i] <= 10^5
    // The integers in nums are distinct.

#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) { // TC : O(n) , SC : O(1)
        // we'll need 4 things - minimum, max, idx of min, idx of max
        int minimum=INT_MAX, maximum=INT_MIN, idxMin=-1, idxMax=-1;

        int n = nums.size();
        int i=0; // pointer from st
        int j=n-1; // pointer from end

        while(i<=j){
            // max = max(max, max(nums[i],nums[j]));

            // 1. Check for Max
            int tempMax = max(nums[i], nums[j]);
            if(maximum < tempMax){ // if we find a new max - store the idx of max
                if(nums[i] > nums[j]) idxMax = i;
                else idxMax = j;
                                
                maximum = tempMax; // update max
            }

            // 2. check for min
            int tempMin = min(nums[i], nums[j]);
            if(minimum > tempMin){ // if we find a new minimum - store the idx of min
                if(nums[i] < nums[j]) idxMin = i; 
                else idxMin = j;

                minimum = tempMin; // update min
            }

            i++;
            j--;
        }

        // once we have the min, max and their idx, we can now calculate the min number of deletions to remove both

        // case 1 : if both are on the left of mid, then min steps will be to del from start of array to the max(inxMin, idxMax) - EXIT
        int midIdx = ceil(n/2);
        if(idxMin < midIdx && idxMax < midIdx){
            return max(idxMin,idxMax) + 1;
        }      
    
        // case 2 : if both are to the right of mid, then min steps will be to del from end to the min(indMin, idxMax) - EXIT
        if(idxMin >= midIdx && idxMax >= midIdx){
            return n - min(idxMin,idxMax);
        }

        // case 3 : if both are in different half:
            // then we will need to find the following
            // 1. find the dist of min(idxMax, idxMin) from the start, call it 'leftmostPt'
            int leftmostPt = min(idxMin, idxMax);
            // 2. find the dist of max(idxMax, idxMin) from end, call it 'rightmostPt'
            int rightmostPt = max(idxMax, idxMin);
            // 3. find dist btw both idx, call it 'dist'
            int dist = rightmostPt - leftmostPt;

            // Now calculate total steps of deletion from both ends, i.e. leftmostPt form start and rightmostPt from end
                // a = leftmostPt + 1 + (n - rightmostpt)
                int a = leftmostPt + 1 + (n - rightmostPt); 
            // now calculate the total steps to del both from front
                // b = rightmostPt +1
                int b = rightmostPt + 1;
            // now cal total steps of deletion from end
                // c = n - leftmostPt
                int c = n - leftmostPt;

            // now pick the min from a, b, c and that will be the answer to return
            return min(a,min(b,c));
    
    }
};



int main(){

    vector<vector<int>> inputs = {{-100000,-99999},{2,10,7,5,4,1,8,6}, {101}, {0,-4,19,1,8,-2,-3,5}};

    for(int i=0; i<4; i++){
        cout << "Case " << i+1 << " Inputs : [";
        
        int n = inputs[i].size();
        
        for(int j=0; j<n; j++){
            if(j<=n-2) cout << inputs[i][j] << ", " ;
            else cout << inputs[i][j];
        }

        cout << "]" << endl;
    }

    vector<int> outputs = {2,5,1,3};

    Solution sol;

    for(int it=0; it<4; it++){
        int ans = sol.minimumDeletions(inputs[it]);

        if(ans = outputs[it]){
            cout << "case " << it+1 << " passed" << endl;
        }else{
            cout << "case " << it+1 << " failed" << endl;
            cout << "Expected Output : " << outputs[it] << endl;
            cout << "Current Output : " << ans << endl;
        }
    }

    return 0;
}