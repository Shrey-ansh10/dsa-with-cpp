// LC-2058 : Find the Minimum and Maximum Number of Nodes Between Critical Points
// A critical point in a linked list is defined as either a local maxima or a local minima.
// A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
// A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

// Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.
// Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

// ** Constraints: **
// => The number of nodes in the list is in the range [2, 10^5]
// => 1 <= Node.val <= 10^5


#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include "../linkedList.hpp"
using namespace std;

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(Node* head) { 
        // TC : O(n+k) -> O(n) : as we're traversing through the list and then through all the critical points
        // SC : O(k) : k stands for number of critical points 

        // some base cases
        if(head->next->next == nullptr) return {-1,-1};

        // find all critiacal points and their position in the list. - we can create a vector and push back the positions of critical points in that

        // for that traverse through the whole list - start from second and go the the second last.

        vector<int> criticalPts = {};

        Node* prev = head; // we start with head as prev as keep updating it as we traverse through the list
        Node* curr = head->next; // 2nd note will be the start point
        int currPos = 2; // track current nodes position in the list


        while(curr->next != nullptr){ // we don't need to worry about case where there are 3 nodes in the list, cos if that happens, there will only be 1 critical point and then we will return {-1,-1} - which is similar to no critical points found
            
            // check if current is a critical point as per the given condition
            if((prev->data < curr->data && curr->data > curr->next->data) // local maxima
                || (prev->data > curr->data && curr->data < curr->next->data) // local minima
                ){ 
                criticalPts.push_back(currPos);
            }

            prev = prev->next; 
            curr = curr->next; 
            currPos++; // increment the position as we move
        }


        int n = criticalPts.size();
        // incase there is no critical point OR only 1 critical point, return 0
        if(n == 0 || n == 1) return {-1,-1};

        if(n==2) return {criticalPts[1] - criticalPts[0], criticalPts[1] - criticalPts[0]};

        // Mininum Distance - will be btw 2 points most closest
        int minDist = INT_MAX;
        int i=0;
        int j=1;

        while(i < n-1){
            int dist = criticalPts[j] - criticalPts[i];
            minDist = min(minDist, dist);

            i++;
            j++;
        }

        // Max Dist will be always btw the first(leftmost) and last(rightmost) critical point
        int maxDist = criticalPts[n-1] - criticalPts[0];

        return {minDist, maxDist};

    }



    // 2nd solution - more space optimal
    vector<int> nodesBetweenCriticalPoints2(Node* head) {

        // TC : O(n)
        // SC : O(1)

        // early exit cases - it's given that there will be 2 or more nodes
        if(head->next->next == nullptr){ // if there are only 2 nodes - exit from here itself
            return {-1,-1};
        }

        // 1. Minimum dist will always btw 2 consecutive points
        int minDist = INT_MAX;

        // 2. Max dist will always between first and last critical point.
        int maxDist = 0;


        // To find critical points - traverse through the whole list - start from second and go the the second last.
        // along with the go, keep track of 3 things. 
        // 1. first critical point's position
        int firstCriticalPointPos = -1;
        // 2. previous critical point's position (last visited)
        int prevCriticalPointPos = -1;
        // 3. current position - current nodes position in the list
        int currPos = 2; 

        Node* prev = head; // we start with head as prev as keep updating it as we traverse through the list
        Node* curr = head->next; // 2nd note will be the start point
        int totalCriticalPoints = 0;


        while(curr->next != nullptr){ // we don't need to worry about case where there are 3 nodes in the list, cos if that happens, there will only be 1 critical point and then we will return {-1,-1} - which is similar to no critical points found
            
            // check if current is a critical point as per the given condition
            if((prev->data < curr->data && curr->data > curr->next->data) // local maxima
                || (prev->data > curr->data && curr->data < curr->next->data) // local minima
                ){

                if(totalCriticalPoints == 0){ // if this is the first critical point
                    firstCriticalPointPos = currPos; // update first critical point 
                    prevCriticalPointPos = currPos; // update last visited critical point
                    totalCriticalPoints++;
                }else{

                    // 1. calculate the minDist : dist btw this and prev critical point
                    int dist = currPos - prevCriticalPointPos;
                    if(dist < minDist) minDist = dist;

                    // 2. calculate max dist : dist btw this and the first point
                    maxDist = currPos - firstCriticalPointPos;

                    // 3. update
                    prevCriticalPointPos = currPos;

                    // 4. update no of critical points found
                    totalCriticalPoints++;
                }
            }

            prev = curr; 
            curr = curr->next; 
            currPos++; // increment the position as we move
        }        

        if(totalCriticalPoints < 2) return{-1,-1}; // when there is only one critical point in the whole linked list
 
        return {minDist, maxDist};

    } 
};


// pass the array and the object - it creates a new linkedlist from that
void createList(vector<int>& nums, List& list){
    for(int values : nums){
        list.push_back(values);
    }
}


int main(){
    
    vector<vector<int>> inputs = {{3,1,2},{5,3,1,2,5,1,2}, {1,3,2,2,3,2,2,2,7}};
    vector<vector<int>> expOutputs = {{-1,-1}, {1,3}, {3,3} };
    
    for(int i=0; i<inputs.size(); i++){
        List newList;
        createList(inputs[i], newList);

        Solution solution;

        vector<int> ans = solution.nodesBetweenCriticalPoints2(newList.getHead());

        if(expOutputs[i] == ans) cout << "Test Case " << i+1 << " passed." << endl;
        else cout << "Test Case " << i+1 << " failed." << endl;
        
    }

    return 0;
}