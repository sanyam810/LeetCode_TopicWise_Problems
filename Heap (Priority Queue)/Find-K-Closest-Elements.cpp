/*

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b

Example :

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]

*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int,int>>pq;
        int n=arr.size();
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};
