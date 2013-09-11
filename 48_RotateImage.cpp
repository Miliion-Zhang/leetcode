/** Rotate Image

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if( n < 2 ) // no need to rotate
            return;
        
        vector<int> pairs(8, 0);
        for( int r = 0; r <= n/2; r++ ){
            if( r == n/2 && (n%2 == 0) )
                continue;
            for( int c = 0; c < n/2; c++ ){
                pairs[0] = c;
                pairs[1] = r;
                getSymetryPoints(pairs, n);
                rotateSymetryPoints(matrix, pairs);
            }
        }
    }
    
    /**
     * Get the four points that symetry.
     * @param pairs: vector, size = 8, and each two stand for row index 
     * and column index of a point. At first, only first 2 are valid, should
     * update others according to them.
     * @param n: the length of side in matrix
     */
    void getSymetryPoints(vector<int> &pairs, int n){
        float center = (n-1) / 2.0;
        int x0 = pairs[0];
        int y0 = pairs[1];
        int x2 = (n-1) - x0;
        int y2 = (n-1) - y0;
        
        int x1 = center + ( center - y0 );
        int y1 = center - ( center - x0 );
        int x3 = (n-1) - x1;
        int y3 = (n-1) - y1;
        pairs[2] = x1; pairs[3] = y1;
        pairs[4] = x2; pairs[5] = y2;
        pairs[6] = x3; pairs[7] = y3;
    }
    
    void rotateSymetryPoints(vector<vector<int> > &matrix, vector<int> &pairs){
        int x0 = pairs[0];  int y0 = pairs[1];
        int x1 = pairs[2];  int y1 = pairs[3];
        int x2 = pairs[4];  int y2 = pairs[5];
        int x3 = pairs[6];  int y3 = pairs[7];
        int tmp = matrix[y0][x0];
        matrix[y0][x0] = matrix[y3][x3];
        matrix[y3][x3] = matrix[y2][x2];
        matrix[y2][x2] = matrix[y1][x1];
        matrix[y1][x1] = tmp;
    }
};
