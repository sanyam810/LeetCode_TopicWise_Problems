/*

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

*/

class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int>q;
        int ans=0;
        q.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                q.push(i);
            }
            else{
                q.pop();
                if(q.empty()){
                    q.push(i);
                }
                else{
                    int len=i-q.top();
                    ans=max(ans,len);
                }
            }
        }
        return ans;
        
    }
};
