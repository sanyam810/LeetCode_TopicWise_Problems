/*

Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, 
then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 
Example :

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int>ans(nums.begin(),nums.end());
        sort(ans.begin(),ans.end());
        int i=0;
        int n=nums.size();
        int j=n-1;
        while(i<n && nums[i]==ans[i]){
            i++;
        }
        while(j>i && nums[j]==ans[j]){
            j--;
        }
        return j+1-i;
        
    }
};
