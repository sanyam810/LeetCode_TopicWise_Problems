/*

A string s is called good if there are no two different characters in s that have the same frequency.
Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string.
For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.


Example :

Input: s = "aab"
Output: 0
Explanation: s is already good.

Constraints:

1 <= s.length <= 105
s contains only lowercase English letters.

*/

class Solution {
public:
    int minDeletions(string s) {
        
        vector<int>freq(26,0);
        
        for(char c:s){
            freq[c-'a']++;
        }
        
        sort(freq.begin(),freq.end());
        int del=0;
        
        for(int i=24;i>=0;i--){
            if(freq[i]==0)break;
            if(freq[i]>=freq[i+1]){
                int prev=freq[i];
                freq[i]=max(0,freq[i+1]-1);
                del+=prev-freq[i];
            }
        }
        return del;
        
        
    }
};
