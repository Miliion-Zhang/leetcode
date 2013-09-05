/** Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top
left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    /**
      * Using DP to solve it.
      * The time is O(m*n) and space is O(n).
      */
    int minPathSum(vector<vector<int> > &grid) {
        int rows = grid.size();
        if( rows < 1 )
            return -1;
        
        int cols = grid[0].size();
        vector<int> pathSum(cols, 0);
        
        pathSum[0] = grid[0][0];
        for( int i = 1; i < cols; i++ )
            pathSum[i] = pathSum[i-1] + grid[0][i];
        
        for( int rp = 1; rp < rows; rp++ ){
            pathSum[0] += grid[rp][0];
            
            for( int cp = 1; cp < cols; cp++ ){
                if( pathSum[cp] > pathSum[cp-1] )// left pos to current pos is shorter
                    pathSum[cp] = pathSum[cp-1] + grid[rp][cp];
                else                             // up pos to current pos is shorter
                    pathSum[cp] += grid[rp][cp];
            }
        }
        
        return pathSum[cols-1];
        
    }
};
