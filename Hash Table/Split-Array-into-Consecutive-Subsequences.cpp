/*

You are given an integer array nums that is sorted in non-decreasing order.
Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:

    Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
    All subsequences have a length of 3 or more.

Return true if you can split nums according to the above conditions, or false otherwise.

A subsequence of an array is a new array that is formed from the original array by deleting some (can be none) of the 
elements without disturbing the relative positions of the remaining elements. (i.e., [1,3,5] is a subsequence of [1,2,3,4,5] while [1,3,2] is not).

*/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        if(nums.size()<3){
            return false;
        }
        
        map<int,int>freq_map;
        map<int,int>subseq_map;
        for(auto n:nums){
            freq_map[n]++;
        }
        for(int n:nums){
            if(freq_map[n]==0){
                continue;
            }
            else if(subseq_map[n-1]>0){
                subseq_map[n-1]--;
                subseq_map[n]++;
            }
            else if(freq_map[n+1]>0 and freq_map[n+2]>0){
                subseq_map[n+2]++;
                freq_map[n+1]--;
                freq_map[n+2]--;
            }
            else{
                return false;
            }
            freq_map[n]--;
        }
        return true;
        
    }
};
