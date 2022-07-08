/*

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example :

Input: nums = [3,2,3]
Output: [3]

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109

*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        if(nums.size()<=1){
            return nums;
        }
        
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        vector<int>ans;
        int max=nums.size()/3;
        for(auto i=mp.begin();i!=mp.end();i++){
            if(i->second>max){
                ans.push_back(i->first);
            }
        }
        return ans;
        
    }
};
