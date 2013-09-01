/** Word Search

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where
"adjacent" cells are those horizontally or vertically neighboring. The same 
letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

struct Position {
    int x;
    int y;
    Position(int x, int y): x(x), y(y) {}
    
    bool isEqual(const Position &pos){
        return x == pos.x && y == pos.y;
    }
    
    void setPos(int x, int y){
        this->x = x;
        this->y = y;
    }
    
    /* Check if the positon in board is valid.
     * Note: not including the maxX and maxY
     */
    bool isValid(int maxX, int maxY){
        return ( x >= 0 && x < maxX )
            && ( y >= 0 && y < maxY );
    }
};

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int rows = board.size();
        if( rows < 1 )
            return false;
        
        int cols = board[0].size();
        
        bool ret = false;
        for( int x = 0; x < rows; x++ ){
            for( int y = 0; y < cols; y++ ){
                ret = exist(board, word, Position(x,y), 0);
                if( ret )
                    break;
            }
            if( ret )
                break;
        }
        return ret;
        
    }
    
    bool exist(vector<vector<char> > &board, string &word,
                Position curPos, int curIndex){
        int rows = board.size();
        int cols = board[0].size();
        
        // Check if current postion is valid
        if( !curPos.isValid(rows, cols) ){
            return false;
        }
        
        // Check if curIndex is valid or not
        if( curIndex >= word.size() )
            return false;
        
        // Check if the char in current position is equal to the
        // char in word or not.
        char c = board[curPos.x][curPos.y];
        if( c != word[curIndex] )
            return false;
        else if( curIndex == word.size()-1 )  // find it!
            return true;
        
        // Change char in current position to 255, this should prevent
        // visiting current postion again.
        // Will change it back when finish searching.
        // Note: This way is working by assuming that word not contains 255
        board[curPos.x][curPos.y] = char(255); 
        
        Position nextPos(0,0);
        bool found = false;
        
        // Check right position
        nextPos.setPos(curPos.x, curPos.y+1);
        if( !found )
            found = exist(board, word, nextPos, curIndex+1);
        
        // Check left position
        nextPos.setPos(curPos.x, curPos.y-1);
        if( !found )
            found = exist(board, word, nextPos, curIndex+1);
        
        // Check upper position
        nextPos.setPos(curPos.x-1, curPos.y);
        if( !found )
            found = exist(board, word, nextPos, curIndex+1);
        
        // Check below position
        nextPos.setPos(curPos.x+1, curPos.y);
        if( !found )
            found = exist(board, word, nextPos, curIndex+1);
        
        // All searched. change current char back
        board[curPos.x][curPos.y] = word[curIndex];
        return found;
    }
};
