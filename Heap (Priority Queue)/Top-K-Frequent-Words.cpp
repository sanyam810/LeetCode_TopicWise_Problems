/**

Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

**/



class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
     map<string,int> mp;
        for(int i = 0; i < words.size(); i++)
        {
            mp[words[i]]++;
        }
        priority_queue<pair<int,string>> pq;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            int nm = it->second*-1;
            pq.push({nm,it->first});
            if(pq.size() > k)pq.pop();
        }
        vector<string> ans;
        while(pq.size()!=0)
        {
            string s = pq.top().second;
            ans.push_back(s);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
