/** Spiral Matrix II

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
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
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix;
        if( n < 1 )
            return matrix;
        
        // initialize matrix with all elements set to 0
        for( int row = 0; row < n; row++ ){
            vector<int> newRow(n, 0);
            matrix.push_back( newRow );
        }
        
        xIndex = 0;
        yIndex = 0;
        curDirection = Right;
        int curNum = 1;
        int m = n; // m is same with question 54, I'm too lazy to change that...
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
                matrix[yIndex][xIndex] = curNum;
                curNum++;
                
                if( step == pos1 || step == pos2 || step == pos3 || step == pos4 )
                    this->changeDirection();
                this->moveToNextPos();
            }
            
            m = m - 2;
            n = n - 2;
        }
        
        return matrix;
        
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
