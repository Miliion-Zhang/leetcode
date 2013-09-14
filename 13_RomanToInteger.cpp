/** Roman to Integer

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for( int i = 0; i < s.size(); i++ ){
            if( i > 0 && cToi(s[i]) > cToi(s[i-1]) )
                result += (cToi(s[i]) - 2 * cToi(s[i-1]));
            else
                result += cToi(s[i]);
        }
        
        return result;
    }
    
    inline int cToi(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default:  return 0;
        }
    }
};
