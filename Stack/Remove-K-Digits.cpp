/*

Given string num representing a non-negative integer num, and an integer k,
return the smallest possible integer after removing k digits from num.

Example:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(num.size()<k){
            return "0";
        }
        if(k==0){
            return num;
        }
        
        stack<char>s;
        string res="";
        
        s.push(num[0]);
        for(int i=1;i<num.size();i++){
            while(!s.empty() && k>0 && num[i]<s.top()){
                --k;
                s.pop();
            }
            s.push(num[i]);
            while(s.size()==1 && num[i]=='0'){
                s.pop();
            }
        }
        
        while(k && !s.empty()){
            --k;
            s.pop();
        }
        
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        
        reverse(res.begin(),res.end());
        if(res.size()==0)return "0";
        return res;
        
    }
};
