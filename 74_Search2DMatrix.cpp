/**

Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int rows = matrix.size();
        if( rows < 1 )
            return false;
        
        int columns = matrix[0].size();
        
        // Binary search using the first column to locate the row index of the target
        int rowBegin = 0;
        int rowEnd = rows-1;
        while( rowBegin+1 < rowEnd ){
            int middle = rowBegin + (rowEnd - rowBegin)/2;
            if( matrix[middle][0] == target )
                return true;
            
            if( matrix[middle][0] < target )
                rowBegin = middle;
            else
                rowEnd = middle;
        }
        
        int row = 0;
        if( matrix[rowEnd][0] <= target )
            row = rowEnd;
        else
            row = rowBegin;
        
        // Now in the row, using binary search to find the target
        int columnBegin = 0;
        int columnEnd = columns-1;
        while( columnBegin+1 < columnEnd ){
            int middle = columnBegin + (columnEnd - columnBegin)/2;
            if( matrix[row][middle] == target )
                return true;
            
            if( matrix[row][middle] < target )
                columnBegin = middle;
            else
                columnEnd = middle;
        }
        
        return matrix[row][columnBegin] == target 
            || matrix[row][columnEnd] == target;
    }
};
