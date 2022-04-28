/*

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, 
where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), 
and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). 
You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Example:


Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2

Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int dir[5]={1,0,-1,0,1};
        
        int m=heights.size();
        int n=heights[0].size();
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        q.push({0,0,0});
        
        while(!q.empty()){
            vector<int>v=q.top();
            q.pop();
            int eff=v[0],x=v[1],y=v[2];
            if(x==m-1 && y==n-1)
                return eff;
        
        if(x<0 || y<0 || x>=m || y>=n || heights[x][y]==0)
            continue;
        
        for(int i=0;i<4;i++){
            int nx=x+dir[i],ny=y+dir[i+1];
            if(nx<=m-1 && ny<=n-1 && nx>=0 && ny>=0)
            q.push({max(eff,abs(heights[x][y]-heights[nx][ny])),nx,ny});  
        }
        heights[x][y]=0;
    }
        
        return 0;
    }       
};
