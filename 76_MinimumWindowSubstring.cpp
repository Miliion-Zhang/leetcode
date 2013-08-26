/** Minimum Window Substring

Given a string S and a string T, find the minimum window in S which will 
contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the 
emtpy string "".

If there are multiple such windows, you are guaranteed that there will always
be only one unique minimum window in S.
*/

class Solution {
public:
    string minWindow(string S, string T) {
        vector<int> wantedCnt(256, 0);   // As a hashtable to store each char's number in T
        vector<int> appearCnt(256, 0);   // As a hashtable, store the S's 
        
        int minW = INT_MAX;  // The min widht of window
        int minLowIndex = 0;   // The start position of min window
        int lowIndex = 0;
        int matched = 0;
        
        for( int i = 0; i < T.size(); i++ )  // Scan T to get the wantedCnt
            wantedCnt[ T[i] ]++;
        
        for( int i = 0; i < S.size(); i++ ){
            if( wantedCnt[ S[i] ] > 0 ){
                appearCnt[ S[i] ]++;
                if( appearCnt[ S[i] ] <= wantedCnt[ S[i] ] )
                    matched++;
            }
            
            // Try to shrink the window by moving the lowIndex to the right
            // if possible.
            // Possible means more char avaible in current window or T does
            // not contain current char.
            if( matched >= T.size() ){
                while( appearCnt[ S[lowIndex] ] > wantedCnt[ S[lowIndex] ]
                    || wantedCnt[ S[lowIndex] ] == 0 ){
                        appearCnt[ S[lowIndex] ]--;
                        lowIndex++;
                }
                
                int width = i - lowIndex + 1;
                if( width < minW ){
                    minW = width;
                    minLowIndex = lowIndex;
                }
            }
        }
        
        if( minW == INT_MAX )
            return "";
        else
            return S.substr(minLowIndex, minW);
    }
};
