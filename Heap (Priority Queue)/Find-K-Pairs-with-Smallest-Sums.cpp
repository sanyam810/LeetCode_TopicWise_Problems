/*

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

Example:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

*/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n1=nums1.size();
        int n2=nums2.size();
        
        vector<vector<int>>res;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        for(int i=0;i<k && i<n1;i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        
        while(!pq.empty() && k--){
            auto curr=pq.top();
            pq.pop();
            
            int i=curr.second.first;
            int j=curr.second.second;
            
            res.push_back({nums1[i],nums2[j]});
            if(j+1<n2){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
            }
        }
        return res;
        
    }
};
