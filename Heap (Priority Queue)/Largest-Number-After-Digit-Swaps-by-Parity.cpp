/*

You are given a positive integer num. You may swap any two digits of num that have the same parity (i.e. both odd digits or both even digits).
Return the largest possible value of num after any number of swaps.

Example :

Input: num = 1234
Output: 3412

Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
Swap the digit 2 with the digit 4, this results in the number 3412.
Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.

*/

class Solution {
public:
    int largestInteger(int num) {
        
        string s=to_string(num);
        
        priority_queue<int>even,odd;
        
        for(auto x:s){
            int temp=x-'0';
            if(temp%2==0){
                even.push(temp);
            }
            else{
                odd.push(temp);
            }
        }
        
        for(auto& x:s){
            int temp=x-'0';
            if(x%2==0){
                x=even.top()+'0';
                even.pop();
            }
            else{
                x=odd.top()+'0';
                odd.pop();
            }
        }
        return stoi(s);
        
    }
};
