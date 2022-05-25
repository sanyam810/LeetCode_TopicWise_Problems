/*

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character.
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.


Example :

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

*/


class Solution {
    public int characterReplacement(String s, int k) {
        
        int n=s.length();
        int[] freq=new int[26];
        
        int window_start=0;
        int max_length=0;
        int max_count=0;
        
        for(int window_end=0;window_end<n;window_end++){
            freq[s.charAt(window_end)-'A']++;
            int curr_char_count=freq[s.charAt(window_end)-'A'];
            max_count=Math.max(max_count,curr_char_count);
            
            while(window_end-window_start-max_count+1>k){
                freq[s.charAt(window_start)-'A']--;
                window_start++;
            }
            max_length=Math.max(max_length,window_end-window_start+1);
        }
        return max_length;
        
    }
}
