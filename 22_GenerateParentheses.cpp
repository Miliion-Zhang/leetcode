/** Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations
of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if( n < 1 )
            return ans;
        
        string par( 2*n, '(' );
        generateParenthesis(1, 0, n, par, ans);
        
        return ans;
    }
    
    void generateParenthesis(int curNum, int unmatchedNum, int n, 
        string &par, vector<string> &ans){
        int leftPosNum = 2*n - curNum + 1;
        if( unmatchedNum < 0 || unmatchedNum > leftPosNum )// illegal
            return;
        
        // The last one, match it and copy it to ans vector
        if( curNum == 2*n ){
            par[2*n -1] = ')';
            ans.push_back( string(par) );
            return;
        }
        
        // set current to '(' and go on searching
        par[ curNum-1 ] = '(';
        generateParenthesis( curNum+1, unmatchedNum+1, n, par, ans );
        
        // set current to ')' and go on searching
        par[ curNum-1 ] = ')';
        generateParenthesis( curNum+1, unmatchedNum-1, n, par, ans );
        
    }
};
