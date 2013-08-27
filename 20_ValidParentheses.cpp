/** Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine
if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but
"(]" and "([)]" are not.

*/

class Solution {
public:
    bool isValid(string s) {
        // When meat with left brackets, push it to stack;
        // and when meat with right brackets, pop one from stack and make sure
        // they are match.
        stack<char> strStack;
        
        for( int i = 0; i < s.size(); i++ ){
            if( s[i] == '(' || s[i] == '{' || s[i] == '[' )
                strStack.push( s[i] );
            else if( s[i] == ')' ){
                if( strStack.size() < 1 
                    || strStack.top() != '(' )
                    return false;
                strStack.pop();
            }
            else if( s[i] == '}' ){
                if( strStack.size() < 1 
                    || strStack.top() != '{' )
                    return false;
                strStack.pop();
            }
            else if( s[i] == ']' ){
                if( strStack.size() < 1 
                    || strStack.top() != '[' )
                    return false;
                strStack.pop();
            }
            else
                return false;
        }
        
        // If stack is not empty, then must have left brackets that can't be matched
        if( strStack.size() > 0 )
            return false;
        else
            return true;
    }
};
