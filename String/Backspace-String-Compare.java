/*

Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

 
Example:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

*/

class Solution {
    public boolean backspaceCompare(String s, String t) {
        
        int i=s.length()-1;
        int j=t.length()-1;
        
        int s_skip=0;
        int t_skip=0;
        
        while(i>=0 || j>=0){
            while(i>=0){
                if(s.charAt(i)=='#'){
                    s_skip+=1;
                    i--;
                }
                else if(s_skip>0){
                    i--;
                    s_skip-=1;
                }
                else{
                    break;
                }
            }
            while(j>=0){
                if(t.charAt(j)=='#'){
                    t_skip+=1;
                    j--;
                }
                else if(t_skip>0){
                    j--;
                    t_skip-=1;
                }
                else{
                    break;
                }
            }
            if(i>=0 && j>=0 && s.charAt(i)!=t.charAt(j)){
                return false;
            }
            if((i>=0)!=(j>=0)){
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
}
