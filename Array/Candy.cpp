/*

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

 

Example :

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Constraints:

n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104

*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n=ratings.size();
        int ans=0;
        
        vector<int> l(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                l[i]=l[i-1]+1;
            }
        }
        
        vector<int>r(n,1);
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                r[i]=r[i+1]+1;
            }
        }
        
        for(int i=0;i<n;i++){
            ans+=max(l[i],r[i]);
        }
        
        return ans;
        
    }
};
