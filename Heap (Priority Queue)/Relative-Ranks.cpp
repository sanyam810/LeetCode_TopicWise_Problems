/*

You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on.
The placement of each athlete determines their rank:

    The 1st place athlete's rank is "Gold Medal".
    The 2nd place athlete's rank is "Silver Medal".
    The 3rd place athlete's rank is "Bronze Medal".
    For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").

Return an array answer of size n where answer[i] is the rank of the ith athlete.

Example :

Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].

*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        vector<string>str(score.size());
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }
        
        for(int i=0;i<3;i++){
            if(pq.empty()==true)break;
            auto a=pq.top();
            pq.pop();
            if(i==0){
                str[a.second]="Gold Medal";
            }
            else if(i==1){
                str[a.second]="Silver Medal";
            }
            else if(i==2){
                str[a.second]="Bronze Medal";
            }
        }
        int i=4;
        while(!pq.empty()){
            auto a=pq.top();
            pq.pop();
            str[a.second]=to_string(i++);
        }
        return str;
        
    }
};
