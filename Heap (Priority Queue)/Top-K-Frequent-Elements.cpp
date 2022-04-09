/**
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

**/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        for(auto i=mp.begin();i!=mp.end();i++){
            pq.push({i->second,i->first});
        }
        
        vector<int>res;
        for(int i=0;i<k;i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
        
    }
};
