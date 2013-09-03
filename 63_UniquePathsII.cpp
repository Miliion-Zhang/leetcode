/** Unique Paths II

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths
would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution {
public:
    /**
     * Using the same method with question 62, see it for more details.
     * Note: the only difference is that if current position is an obstacle,
     *       then paths[curPos] = 0 which means it is unreachable.
     */
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int rows = obstacleGrid.size();
        if( rows < 1 )
            return 0;
        int cols = obstacleGrid[0].size();
        
        vector<int> paths(cols, 0);
        if( obstacleGrid[0][0] == 1 )
            paths[0] = 0;
        else
            paths[0] = 1;
        
        for(int r = 0; r < rows; r++){
            if( r > 0 ){
                paths[0] = (obstacleGrid[r][0] == 1) ? 0 : paths[0];
            }
            
            for(int c = 1; c < cols; c++){
                if( obstacleGrid[r][c] == 1 )
                    paths[c] = 0;
                else
                    paths[c] += paths[c-1];
            }
            
        }
        
        return paths[cols-1];
    }
};
