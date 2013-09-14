/** Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating
characters. For example, the longest substring without repeating letters for
"abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring
is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        if( s.size() < 1 )
            return maxLen;
        
        maxLen = 1;
        int leftPos = 0;
        for( int i = 1; i < s.size(); i++ ){
            
            for(int j = leftPos; j < i; j++ ){
                if( s[j] == s[i] ){
                    leftPos = j+1;
                    break;
                }
            }
            
            int curLen = i - leftPos + 1;
            maxLen = (curLen > maxLen) ? curLen : maxLen;
        }
        
        return maxLen;
    }
};
