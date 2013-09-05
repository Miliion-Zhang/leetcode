/** Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of
the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
    /**
      * Different directions
      */
    enum Direction{Right=1,  Down, Left, Up};
    
    Direction curDirection; // current direction
    int xIndex;                    // current column index
    int yIndex;                    // current row index
    
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        int m = matrix.size();
        if( m < 1 )
            return ret;
        
        int n = matrix[0].size();
        
        // if only have one row or only have one column, process them
        if( m == 1 ){
            ret = matrix[0];
            return ret;
        }
        else if( n == 1 ){
            for( int i = 0; i < m; i++ )
                ret.push_back( matrix[i][0] );
            return ret;
        }
        
        // m > 1 && n > 1
        xIndex = 0;
        yIndex = 0;
        curDirection = Right;
        while( m > 0 && n > 0 ){
            // four postion that should change direction
            int pos1 = n-1; 
            int pos2 = pos1 + (m-1);
            int pos3 = pos2 + (n-1); 
            int pos4 = pos3 + (m-2); // the last one in current circle

            // if m=1 && n=1, then the pos4 is negtive, must make sure pos4
            //is non-negtive, so the last element can be accessed.
            pos4 = (pos4 >= 0) ? pos4 : 0; 
            
            for( int step = 0; step <= pos4; step++ ){
                 // notice the order!!! xIndex is the column Index
                ret.push_back( matrix[yIndex][xIndex] ); 
                if( step == pos1 || step == pos2 || step == pos3 || step == pos4 )
                    this->changeDirection();
                this->moveToNextPos();
            }
            
            m = m - 2;
            n = n - 2;
        }
        
        return ret;
    }
    
    
    void changeDirection(){
        switch( curDirection ){
            case Right:
                curDirection = Down;
                break;
            case Down:
                curDirection = Left;
                break;
            case Left:
                curDirection = Up;
                break;
            case Up:
                curDirection = Right;
                break;
            default:    // not change direction
                break;
        }
    }
    
    
    void moveToNextPos(){
        switch( curDirection ){
            case Right:
                xIndex++;
                break;
            case Down:
                yIndex++;
                break;
            case Left:
                xIndex--;
                break;
            case Up:
                yIndex--;
                break;
            default:    // not move
                break;
        }
    }
};
