/** Substring with Concatenation of All Words

You are given a string, S, and a list of words, L, that are all of the same length. 
Find all starting indices of substring(s) in S that is a concatenation of each 
word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        if( L.size() < 1 )
            return ret;
        
        int wordLen = L[0].size();
        int rows = L.size();
        if( S.size() < rows * wordLen ) // S is not long enough
            return ret;
        
        map<string, int> expectCnt;
        map<string, int> actualCnt;
        for( int i = 0; i < L.size(); i++ )
            expectCnt[L[i]]++;
        
        
        for( int i = 0; i <= S.size() - rows*wordLen; i++ ){
            actualCnt.clear();
            int j = 0;
            for( j = 0; j < rows; j++ ){
                string w = S.substr( i + j*wordLen, wordLen );
                if( expectCnt.find(w) != expectCnt.end() )
                    actualCnt[w]++;
                else
                    break;
                    
                if( actualCnt[w] > expectCnt[w] )
                    break;
                
            }
            
            if( j == rows )
                ret.push_back(i);
        }
        
        return ret;
    }
};
