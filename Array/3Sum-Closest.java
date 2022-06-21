/*

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 
Example:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        
        Arrays.sort(nums);
        int result=nums[0]+nums[1]+nums[nums.length-1];
        
        for(int i=0;i<nums.length-2;i++){
            int a=i+1;
            int b=nums.length-1;
            
            while(a<b){
            int cursum=nums[i]+nums[a]+nums[b];
            if(cursum>target){
                b-=1;
            }
            else{
                a+=1;
            }
            if(Math.abs(cursum-target)<Math.abs(result-target)){
                result=cursum;
            }
            }
        }
        return result;
        
    }
}
