/*

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

Example:

Input: nums = [1,1,1], k = 2
Output: 2

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        int cursum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            cursum+=nums[i];
            if(cursum==k){
                count++;
            }
            if(mp.count(cursum-k)){
                count+=mp[cursum-k];
            }
            mp[cursum]++;
        }
        return count;
    }
};
