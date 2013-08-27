/** Letter Combinations of a Phone Number

Given a digit string, return all possible letter combinations that the number
could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be
in any order you want.

*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Initialize a map from digits to possible string.
        vector<string> map;
        map.push_back( string("0") ); //map 0
        map.push_back( string("1") ); //map 1
        map.push_back( string("abc") ); //map 2
        map.push_back( string("def") ); //map 3
        map.push_back( string("ghi") ); //map 4
        map.push_back( string("jkl") ); //map 5
        map.push_back( string("mno") ); //map 6
        map.push_back( string("pqrs") ); //map 7
        map.push_back( string("tuv" ) ); //map 8
        map.push_back( string("wxyz") ); //map 9
        
        vector<string> ans;
        ans.push_back("");  // If input is empty, then return a vector only contains ""
        for( int i = 0; i < digits.size(); i++ ){
            // Get the index in map
            int index = int( digits[i] - '0' );
            if( index < 0 || index > 9 ){
                ans.clear();
                break;
            }
            
            int existSize = ans.size();
            string mappedStr = map[index];
            
            // combinate all possible chars of current digits and existing string in
            // ans to get all conditions of new string and put them to ans.
            for( int j = 1; j < mappedStr.size(); j++ ){
                
                for( int k = 0; k < existSize; k++ ){
                    string s( ans[k] );
                    s.push_back( mappedStr[j] );
                    ans.push_back( s );
                }
            }
            
            // The first char of current digits is processed alone
            for( int k = 0; k < existSize; k++ ){
                ans[k].push_back( mappedStr[0] );
            }
        }
        
        return ans;
    }
};
