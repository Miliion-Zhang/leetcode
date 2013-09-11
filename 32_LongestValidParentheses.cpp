/** Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the
longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is 
"()()", which has length = 4.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        // indexs of valid '(' or invalid ')' are saved in stack.
        // valid '(' means waiting for matching; and invalid ')'
        // means already can't be matched.
        stack<int> pstack;
        
        int curLen = 0;
        for( int i = 0; i < s.size(); i++ ){
            if( s[i] == '(' ){
                pstack.push( i );
            }                
            else if( !pstack.empty() && s[pstack.top()]=='(' ){
                pstack.pop();
                maxLen = max(maxLen, pstack.empty() ? i+1 : i - pstack.top() );                
            }
            else{   // can't match: stack is empty or top() != '('
                pstack.push( i );
            }
        }
        
        return maxLen;
    }
};
