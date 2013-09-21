/** Anagrams

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ret;
        
        // sort by length
        sort(strs.begin(),strs.end(),Solution::AcsByLen);
        
        vector<vector<int> > cnts;
        for( int i = 0; i < strs.size(); i++ ){
            vector<int> cnt(26+1, 0);
            getCountChar(strs[i], cnt);
            cnts.push_back(cnt);
        }
        
        vector<bool> hasVisited(strs.size(), false);
        for( int i = 0; i < cnts.size(); i++ ){
            if( hasVisited[i] )
                continue;
            
            bool found = false;
            for( int j = i+1; j < cnts.size(); j++ ){
                if( hasVisited[j] )
                    continue;
                
                if( strs[i].size() != strs[j].size() )
                    break;
                
                if( isEqualCnt(cnts[i], cnts[j]) ){
                //if( cnts[i] == cnts[j] ){
                    found = true;
                    ret.push_back(strs[j]);
                    hasVisited[j] = true;
                }
            }
            
            if( found )
                ret.push_back(strs[i]);
        }
        
                
        return ret;
    }
    
    static bool AcsByLen(const string &stra, const string &strb) {
        return stra.size() < strb.size();
    }
    
    
    /**
     * Calculate the count of each char, must make sure that all
     * char in str are lower-case and the size of cnt is 26 + 1,
     * and the last one in cnt is the self-defined hash value of cnt vector.
     */
    inline void getCountChar(string &str, vector<int> &cnt){
        for(int i = 0; i < str.size(); i++){
            int index = int(str[i] - 'a');
            cnt[index]++;
        }
        
        // calculate self-defined hash value
        for(int i = 0; i < 26; i++){
            cnt[26] += (cnt[i] << i);
        }
    }
    
    inline bool isEqualCnt(vector<int> &cnt1, vector<int> &cnt2){
        if( cnt1[26] != cnt2[26] )
            return false;
        
        return (cnt1 == cnt2);
    }
};


/** 
 * Another version.
 * The idea is sort every string in strs, so that the anagrams become the same
 * string.
 */
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        if (strs.size() <= 1) return res;
        map<string, int> anagram;
        for (int i = 0; i < strs.size(); ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (anagram.find(s) == anagram.end()) {
                anagram.insert(make_pair(s, i));
            } else {
                if (anagram[s] >= 0) {
                    res.push_back(strs[anagram[s]]);
                    anagram[s] = -1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};