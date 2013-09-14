/** ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
of rows like this: (you may want to display this pattern in a fixed font for
better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number
of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution {
public:
    /**
     * Can find out the index mapping rule from the following examples:
     * (1) nRows = 2
     *     0 2 4 6 8...
     *     1 3 5 7 9
     *
     * (2) nRows = 3
     *     0   4   8    12...
     *     1 3 5 7 9 11 13
     *     2   6   10   14
     *
     * (3) nRows = 4
     *     0     6      12       18 ...
     *     1   5 7   11 13    17
     *     2 4   8 10   14 16
     *     3     9      15
     */
    string convert(string s, int nRows) {
        if( nRows <= 1 || s.size() < 2 )
            return s;
        
        string ret;
        int period = 2*nRows - 2;   // Period of each zigzag
        
        // write the first row
        int curPos = 0;
        while( curPos < s.size() ){
            ret.push_back( s[curPos] );
            curPos += period;
        }
                
        // write middle rows
        for( int i = 1; i < nRows-1; i++ ){
            int curPos1 = i;
            int curPos2 = period - i;
            while(1){
                if( curPos1 < s.size() ){
                    ret.push_back( s[curPos1] );
                }
                else
                    break;
                
                if( curPos2 < s.size() ){
                    ret.push_back( s[curPos2] );
                }
                else
                    break;
                
                curPos1 += period;
                curPos2 += period;
            }
        }
        
        // write the last row
        curPos = nRows - 1;
        while( curPos < s.size() ){
            ret.push_back( s[curPos] );
            curPos += period;
        }
        
        return ret;
    }
};
