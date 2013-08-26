/** Maximal Rectangle

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
containing all ones and return its area.
*/


class Solution {
public:
    /**
     * This solution is based on qestion 84, just transform this question to
     * question 84 and solve it with in O(n) time. But the time all is O(n*n)
     * because we should iterate row by row in the 2D binary matrix and 
     * at each row also should update the height vector.
     */
    int maximalRectangle(vector<vector<char> > &matrix) {
        int rows = matrix.size();
        if( rows < 1 )
            return 0;
        
        int columns = matrix[0].size();
        vector<int> height(columns, 0);
        int maxArea = 0;
        for( int r = 0; r < rows; r++ ){
            for( int c = 0; c < columns; c++ ){
                if( matrix[r][c] == '1' )
                    height[c] += 1;
                else
                    height[c] = 0;
            }
            int area = largestRectangleArea( height );
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
    
    /** 
     * The function of solution for question 84: Largest Rectangle in Histogram .
     * See it's cpp for more details.
      */
    int largestRectangleArea(vector<int> &height) {
        
        stack<int> hstack;
        stack<int> wstack;
        hstack.push(0); // the ascending sequences of height
        wstack.push(0); // the width of itmes in hstack
        int area = 0;
        
        for( int i = 0; i < height.size(); i++ ){
            if( height[i] >= hstack.top() ){ 
                hstack.push( height[i] );
                wstack.push( 1 );
            }
            else {
                int minH = INT_MAX;
                int width = 0;
                while( hstack.top() > height[i] ){
                    minH = min( minH, hstack.top() );
                    width += wstack.top();
                    hstack.pop();
                    wstack.pop();
                    area = max( area, minH * width );
                }
                
                hstack.push( height[i] );
                wstack.push( width + 1 );
            }
        }
        
        // pop all out
        int minH = INT_MAX;
        int width = 0;
        while( !hstack.empty() ){
            minH = min( minH, hstack.top() );
            width += wstack.top();
            hstack.pop();
            wstack.pop();
            area = max( area, minH * width );
        }
        
        return area;
    }
};