/** Set Matrix Zeroes

Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int rows = matrix.size();
        if( rows < 1 )
            return;
        
        int cols = matrix[0].size();
        bool row1stZero = false;
        bool col1stZero = false;
        //using first row and col as storage
        //1.search zero in first row and col to determin it's own status
        for( int i = 0; i < cols; i++ ){
            if( matrix[0][i] == 0 ){
                row1stZero = true;
                break;
            }
        }
        
        for( int i = 0; i < rows; i++ ){
            if( matrix[i][0] == 0 ){
                col1stZero = true;
                break;
            }
        }
        
         //2.search zeros in other position to sign the first row and col
        for(int ri = 1; ri < rows; ++ri) {
            for(int ci = 1; ci < cols; ++ci) {
                if(matrix[ri][ci] == 0) {
                    matrix[0][ci] = 0;
                    matrix[ri][0] = 0;
                }
            }
        }
        
        
        //3.set zeroes in other positions according to first col and row
        for(int ri = 1; ri < rows; ++ri) {
            for(int ci = 1; ci < cols; ++ci) {
                if(matrix[0][ci] == 0 || matrix[ri][0] == 0) {
                    matrix[ri][ci] = 0;
                }
            }
        }
        
        //4.set zeroes for first row and col
        if( row1stZero ){
            for( int j = 0; j < cols; j++ )
                matrix[0][j] = 0;
        }
        
        if( col1stZero ){
            for( int i = 0; i < rows; i++ )
                matrix[i][0] = 0;
        }
        
    }
};
