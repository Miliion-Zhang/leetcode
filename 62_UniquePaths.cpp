/** Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in 
the diagram below).

The robot can only move either down or right at any point in time. The robot
is trying to reach the bottom-right corner of the grid (marked 'Finish' in the
diagram below).

How many possible unique paths are there?
*/

class Solution {
public:
    /**
     * Using DP method, time is O(m*n) and space is O(n).
     * 
     * using a m x n array to store the paths from top-left corner
     * to that position. When want to calculate the paths in position
     * (r,c), only need add (r-1,c) and (r, c-1) together if exists.
     * 
     * Note: can be optimize to O(n) space, because we only need the
     *       paths to bottom-right corner, so when updating each row
     *       of m x n array, we can update them in position, which
     *       means only need to add left position's paths to current
     *       one's, and move to next.
     */
    int uniquePaths(int m, int n) {
        if( m < 1 || n < 1 )
            return 0;
        
        int *paths = new int[n];
        memset(paths, 0, sizeof(int)*n);
        
        paths[0] = 1;
        for( int row = 0; row < m; row++ ){
            for( int col = 1; col < n; col++ ){
                paths[col] += paths[col-1];
            }
        }
        
        return paths[n - 1];
    }
    
    
    /**
     * Unoptimized version, will take O(m*n) space.
     */
    int uniquePathsUnoptimized(int m, int n) {
        if( m < 1 || n < 1 )
            return 0;
        
        int *paths = new int[ m * n ];
        memset(paths, 0, sizeof(int)*m*n);
        
        paths[0] = 1;
        for( int row = 0; row < m; row++ ){
            for( int col = 0; col < n; col++ ){
                int curIndex = getIndex(row, col, n);
                if( row > 0 ){
                    int upperIndex = getIndex( row-1, col, n );
                    paths[curIndex] += paths[upperIndex];
                }
                
                if( col > 0 ){
                    int leftIndex = getIndex( row, col-1, n );
                    paths[curIndex] += paths[leftIndex];
                }
            }
        }
        
        return paths[m*n - 1];
    }

    /**
     * transform index of two dimensions array to single dimension array.
     * @param row: row index, begin from 0
     * @param col: column index, begin from 0
     * @param lenPerRow: length of a row, equal to the number of columns
     * @return: index in single dimension array, start from 0
     */
    inline int getIndex(int row, int col, int lenPerRow){
        return row * lenPerRow + col;
    }
};
