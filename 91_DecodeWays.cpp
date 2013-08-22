/** Decode Ways

    A message containing letters from A-Z is being encoded to numbers using
    the following mapping:

    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26
    Given an encoded message containing digits, determine the total number 
    of ways to decode it.

    For example,
    Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

    The number of ways decoding "12" is 2.
*/


class Solution {
public:
    /**
     * This question is a Markov chain.
     * So we can calculate the number of possible ways decoding string
     * level by level.
     * 
     * Note: The given string can be illegal and can not be decoded.
     */
    int numDecodings(string s) {
        int len = s.length();
        if( len < 1 )
            return 0;
        
        if( s[0] == '0' )
            return 0;
        
        int allNum = 1;         // All possible combination
        int lastDigAlone = 1;   // The cominations with the last digital is alone.
        for( int i = 1; i < len ; i++ ){
            char last = s[i-1];
            char cur = s[i];
            
            // '0' must be '10' or '20', so the last char must be alone and
            // must be '1' or '2'
            if( cur == '0' ){
                if( last > '2' || last == '0' )
                    return 0;
                else {
                    allNum = lastDigAlone;
                    lastDigAlone = 0;
                }                 
            }
            else {
                /**
                 * Two possible condition:
                 *  1) Can be decoded with the last char together.
                 *     a) Add the new digital to all combinations as the last single digital.
                 *     b) Bond with last char together to be a new combination.
                 *  2) Can not be decode with the last char together
                 *     a) Add the new digital to all combinations as the last single digital.
                 */
                int n = (int)(last - '0') * 10 + (int)(cur - '0');
                if( n <= 26 ){
                    int digAlone = allNum;
                    allNum = allNum + lastDigAlone;
                    lastDigAlone = digAlone;
                }
                else{
                    lastDigAlone = allNum;
                    allNum = allNum;
                }
            }
        }
        
        return allNum;
        
    }
};