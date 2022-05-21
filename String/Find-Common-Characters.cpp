/*

Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates).
You may return the answer in any order.

Example:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

*/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
     
        vector<string>res;
        
        for(auto c:words[0]){
            bool isPresent=true;
            string s;
            for(int i=1;i<words.size();i++){
                int index=words[i].find(c);
                if(index!=-1){
                    words[i].erase(index,1);
                }
                else{
                    isPresent=false;
                    break;
                }
            }
            if(isPresent)res.push_back(s+=c);
        }
        return res;
        
    }
};
