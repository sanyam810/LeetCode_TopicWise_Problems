/*

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 
Example :
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(nums.size()==0){
            return {-1,-1};
        }
        
        return {search(nums,target,true),search(nums,target,false)};
        
    }
    
    int search(vector<int>nums,int k,bool flag){
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>k){
                high=mid-1;
            }
            else if(nums[mid]<k){
                low=mid+1;
            }
            else{
                ans=mid;
                if(flag){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return ans;
    }
    
};
