/*

You are given a string s that consists of lower case English letters and brackets.
Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

Example :

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

*/

class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<int>index;
        stack<char>brackets;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                brackets.push(s[i]);
                index.push(i+1);
            }
            if(s[i]==')' && brackets.top()=='('){
                reverse(s.begin()+index.top(),s.begin()+i);
                index.pop();
                brackets.pop();
            }
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='(' && s[i]!=')'){
                ans+=s[i];
            }
        }
        return ans;
        
    }
};
