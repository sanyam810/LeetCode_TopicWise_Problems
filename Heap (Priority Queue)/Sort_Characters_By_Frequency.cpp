/*
Given a string s, sort it in decreasing order based on the frequency of the characters.
The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.


Example:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

*/



class Solution {
public:
    string frequencySort(string s) {
        
        map<int,int>mp;
        for(char c:s){
            mp[c]++;
        }
        
        priority_queue<pair<int,char>>pq;
        
        for(auto i:mp){
            char ch=i.first;
            int count=i.second;
            pq.push({count,ch});
        }
        
        string ans="";
        while(!pq.empty()){
            pair<int,char>p=pq.top();
            pq.pop();
            int count=p.first;
            while(count>0){
                ans+=p.second;
                count--;
            }
        }
        return ans;
        
    }
};
