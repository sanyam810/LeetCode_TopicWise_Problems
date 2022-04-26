/*

You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.
Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

Example:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.

*/

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
        vector<int>index;
        
        for(int i=0;i<nums.size();i++){
            min_heap.push({nums[i],i});
            if(min_heap.size()>k)min_heap.pop();
        }
        
        while(min_heap.size()){
            index.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        sort(index.begin(),index.end());
        for(int i=0;i<index.size();i++){
            ans.push_back(nums[index[i]]);
        }
        
        return ans;
        
    }
};
