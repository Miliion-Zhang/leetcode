/** Valid Sudoku

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
(http://sudoku.com.au/TheRules.aspx)

The Sudoku board could be partially filled, where empty cells are filled with 
the character '.'.



A partially filled sudoku which is valid.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int rows = board.size();
        if( rows != 9 )
            return false;
        int cols = board[0].size();
        if( cols != 9 )
            return false;
        
        // must be 10 rooms for 1-9, otherwise should use
        // n-1 as index in cnt.
        vector<int> cnt(9+1, 0);
        
        // check each row
        for( int rp = 0; rp < rows; rp++ ){
            resetCnt(cnt);
            for( int cp = 0; cp < cols; cp++ ){
                int n = int( board[rp][cp] - '0' );
                if( n < 0 || n > 9 )
                    continue;
                
                if( cnt[n] > 0 )
                    return false;
                else
                    cnt[n] = 1;
            }
        }
        
        // check each column
        for( int cp = 0; cp < cols; cp++ ){
            resetCnt(cnt);
            for( int rp = 0; rp < rows; rp++ ){
                int n = int( board[rp][cp] - '0' );
                if( n < 0 || n > 9 )
                    continue;
                
                if( cnt[n] > 0 )
                    return false;
                else
                    cnt[n] = 1;
            }
        }
        
        // check each 3*3 small grid
        for( int rp = 0; rp < rows; rp += 3 ){
            for( int cp = 0; cp < cols; cp += 3 ){
                resetCnt(cnt);
                for( int i = rp; i < rp+3; i++ ){
                    for( int j = cp; j < cp+3; j++ ){
                        int n = int( board[i][j] - '0' );
                        if( n < 0 || n > 9 )
                            continue;
                
                        if( cnt[n] > 0 )
                            return false;
                        else
                        cnt[n] = 1;
                    }
                }
            }
        }
        
        //all checked
        return true;
    }
    
    inline void resetCnt(vector<int> &cnt){
        for(int i = 0; i < cnt.size(); i++)
            cnt[i] = 0;
    }
};
