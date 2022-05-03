/*

You are given a positive integer num consisting of exactly four digits. Split num into two new integers new1 and new2 by using the digits found in num.
Leading zeros are allowed in new1 and new2, and all the digits found in num must be used.

Return the minimum possible sum of new1 and new2.

Example :

Input: num = 2932
Output: 52
Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.

*/

class Solution {
public:
    int minimumSum(int num) {
        
        vector<int>ans;
        while(num){
            ans.push_back(num%10);
            num/=10;
        }
        sort(ans.begin(),ans.end());
        int a=0;
        int b=0;
        
        a=ans[0]*10 +ans[3];
        b=ans[1]*10 +ans[2];
        return a+b;
        
        
    }
};
