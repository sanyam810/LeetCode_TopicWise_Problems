/*

You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

Example:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"

Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"

*/

class Solution {
public:
    
    string ans;
    
    void dfs(int i, vector<int> &pos, vector<int> &vis, vector<vector<int>> &g) {   
        vis[i]++;
        pos.push_back(i);
        for(auto child: g[i]){
            if (!vis[child]) dfs(child, pos, vis, g);
     }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
      int n = s.size();
        ans = s;
        vector<vector<int>> g(n);
        for(auto i: pairs) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
    
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++) {
            if (!vis[i]) {
                vector<int> pos;
                dfs(i, pos, vis, g);
                string tmp = "";
                for(auto c: pos) {
                    tmp += s[c];
                }
                sort(pos.begin(), pos.end());
                sort(tmp.begin(), tmp.end());
                for(int z = 0; z<pos.size(); z++) {
                    ans[pos[z]] = tmp[z];
                }
            }
    }
    return ans;
}
};
