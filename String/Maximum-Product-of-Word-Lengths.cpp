/*

Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.
If no such two words exist, return 0.

Example:

Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".

*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n=words.size();
        vector<int>mask(n,0);
        
        for(int i=0;i<n;++i){
            int w_bin=0;
            for(int j=0;j<words[i].size();j++){
                w_bin|=1<<(words[i][j]-'a');
            }
            mask[i]=w_bin;
        }
        
        int res=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if((mask[i]&mask[j])==0){
                    int ans=words[i].size()*words[j].size();
                     res=max(res,ans);
                }
            }
        }
        
        return res;
    }
};
