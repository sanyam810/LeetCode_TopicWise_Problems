/*

A string is good if there are no repeated characters.
Given a string s, return the number of good substrings of length three in s.
Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

A substring is a contiguous sequence of characters in a string.

 

Example :

Input: s = "xyzzaz"
Output: 1
Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
The only good substring of length 3 is "xyz".

*/

class Solution {
public:
    int countGoodSubstrings(string s) {
        
        int count=0;
        if(s.size()-1<=1)return 0;
        for(int i=0;i<s.size()-2;i++){
            if(s[i]==s[i+1] || s[i+1]==s[i+2] || s[i+2]==s[i]){
                continue;
            }
            count+=1;
        }
        return count;
        
    }
};
