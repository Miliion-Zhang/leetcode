/** Pascal's Triangle

    Given numRows, generate the first numRows of Pascal's triangle.

    For example, given numRows = 5,
    Return

    [
         [1],
        [1,1],
       [1,2,1],
      [1,3,3,1],
     [1,4,6,4,1]
    ]

*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > triangle;
        if( numRows < 1 )
            return triangle;
        
        vector<int> firstRow(1,1);
        vector<int> secondRow(2,1);
        
        if( numRows == 1 ){
            triangle.push_back( firstRow );
            return triangle;
        }
        
        if( numRows == 2 ){
            triangle.push_back( firstRow );
            triangle.push_back( secondRow );
            return triangle;
        }
        
        
        triangle.push_back( firstRow );
        triangle.push_back( secondRow );
        
        int curRowNum = 3;
        while( curRowNum <= numRows ){
            vector<int> curRow(curRowNum,1);
            vector<int> lastRow = triangle.back();
            for(int i=1; i < curRowNum-1 ; i++)
                curRow[i] = lastRow[i-1] + lastRow[i];
            triangle.push_back( curRow );
            curRowNum ++;
        }
        
        return triangle;
    }
};