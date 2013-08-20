/** Longest Common Prefix
	Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        if( strs.size() < 1 )
            return prefix;
        
        if( strs.size() == 1 )
            return strs[0];
        
        bool isCommon = true;
        int commonIndex = 0;
        while( true ){
            char c = strs[0][commonIndex];
            for( int i = 1; i < strs.size(); i++ ){
                if( commonIndex >= strs[i].size() || c != strs[i][commonIndex] ){
                    isCommon = false;
                    break;
                }
            }
            
            if( isCommon ){
                prefix.push_back(c);
                commonIndex++;
            }
            else
                break;
        }
        
        return prefix;
    }
};