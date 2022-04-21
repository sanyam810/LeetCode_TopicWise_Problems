/*

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Example:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        int max_subarray=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                sum+=1;
            }
            else if(nums[i]==0){
                sum+=-1;
            }
            if(sum==0){
                if(max_subarray<i-0+1){
                    max_subarray=i+1;
                }
            }
            else if(mp.find(sum)!=mp.end()){
                int len=i-mp[sum];
                if(max_subarray<len){
                    max_subarray=len;
                }
            }
            else{
                mp[sum]=i;
            }
        }
        return max_subarray;
        
        
    }
};
