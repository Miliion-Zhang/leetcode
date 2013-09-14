/** Longest Palindromic Substring

Given a string S, find the longest palindromic substring in S. You may assume
that the maximum length of S is 1000, and there exists one unique longest
palindromic substring.
*/

class Solution {
public:
    /**
     * A straightforward solution by searching the longest palindromic string
     * at each point and regard that point as central.
     */
    string longestPalindrome(string s) {
        int maxLen = 0;
        int maxLeftPos = 0;
        int maxRightPos = 0;
        
        for( int i = 0; i < s.size(); i++ ){
            int curLen = 0;
            int leftPos = i-1;
            int rightPos = i+1;
            
            curLen = 1 + getSymmetryLen(s, leftPos, rightPos);
            if( curLen > maxLen ){
                maxLen = curLen;
                maxLeftPos = leftPos;
                maxRightPos = rightPos;
            }
            
            if( i < s.size()-1 && s[i] == s[i+1] ){
                leftPos = i-1;
                rightPos = i+2;
                curLen = 2 + getSymmetryLen(s, leftPos, rightPos);
                if( curLen > maxLen ){
                    maxLen = curLen;
                    maxLeftPos = leftPos;
                    maxRightPos = rightPos;
                }
            }
        }
        
        string ret;
        for( int i = maxLeftPos; i <= maxRightPos; i++ )
            ret.push_back( s[i] );
        
        return ret;
    }
    

    int getSymmetryLen(string &s, int &leftPos, int &rightPos){
        int len = 0;
        while(1){
            if( leftPos < 0 || rightPos >= s.size() )
                break;
            
            if( s[leftPos] == s[rightPos] ){
                len += 2;
                leftPos--;
                rightPos++;
            }
            else        // not symmetry
                break;
        }
        
        // return to the last symmetry position
        leftPos++;
        rightPos--;
        
        return len;
    }
};
