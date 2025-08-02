/*
QUESTION:-
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
*/

/*
APPROACH:-
-> The idea is while traversing the array if we found any zero then we have to swap it with next non-zero
*/

// CODE:-
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        ///bruteee/////
        // vector<int>temp;
        // int n=nums.size();
        // for(int i=0; i<n;i++){
        //     if(nums[i]!=0)
        //     temp.push_back(nums[i]);
        // }
        // int nz=temp.size();

        // for(int i=0;i<nz;i++){
        //     nums[i]=temp[i];
        // }

        //     for(int i=nz; i<n;i++){
        //         nums[i]=0;
        //     }
        // }


        
        /////////////////////////////optimal////////////////////////
        int n=nums.size();

        int j=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                break;

            }
        }
        if(j==-1) return;

        for(int i=j+1;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};
        // TIME COMPLEXITY = O(N) (as we moving j throught the array only once)
        // SPACE COMPLEXITY = O(0)
