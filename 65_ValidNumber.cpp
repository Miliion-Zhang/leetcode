/** Valid Number

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should
gather all requirements up front before implementing one.
*/

class Solution {
public:
    bool isNumber(const char *s) {
        string strNum = stripSpace(s);
        
        if( strNum.empty() )// empty or contains illegal char
            return false;        
        
        // chech if it is scientific notation
        int eNum = findCharNum( strNum, 'e' );
        if( eNum > 1 )
            return false;
        
        if( eNum == 1 ){                // scientific notation
            vector<string> strVector = splitString( strNum, 'e' );
            if( strVector.size() != 2 )
                return false;
            
            if( !isInteger( strVector[1] ) )
                return false;
            
            return isDecimalOrInteger( strVector[0] );
        }
        else{                           // not scientific notation
            return isDecimalOrInteger( strNum );
        }
    }
    
    string stripSpace(const char *s){
        string ret;
        int start = -1;
        int end = -1;
        int p = 0;
        while(s[p] != '\0'){
            if( start == -1 && s[p] != ' ' )
                start = p;
            
            if( s[p] != ' ' )
                end = p;
            
            p++;
        }
        
        if( start < 0 )// not contain valid char
            return ret;
        
        for( int i = start; i <= end; i++ ){
            if( (s[i] <= '9' && s[i] >= '0')
                || s[i] == '.'
                || s[i] == 'e' 
                || s[i] == '+'
                || s[i] == '-'
                ){
                ret.push_back( s[i] );
            }
            else if( s[i] == 'E' ){
                ret.push_back( 'e' );
            }
            else{   // not valid char
                ret = string();
                return ret;
            }
        }
        
        return ret;
    }
    
    
    
    int findCharNum( const string &src, char c ){
        int num = 0;
        for( int i = 0; i < src.size(); i++ )
            if( src[i] == c )
                num++;
        return num;
    }
    
    
    vector<string> splitString(const string &src, char split = ' '){
        vector<string> ret;
        string s;
        for( int i = 0; i < src.size(); i++ ){
            if( src[i] != split )
                s.push_back( src[i] );
            else{
                if( !s.empty() ){
                    ret.push_back( s );
                    s = string();
                }
            }
        }
        
        if( !s.empty() )
            ret.push_back(s);
        
        return ret;
    }
    
    
    bool isInteger(const string &strNum, bool allowSign = true){
        if( strNum.size() < 1 )
            return false;
        
        for( int i = 0; i < strNum.size(); i++ ){
            if( i == 0 && ( strNum[0] == '+' || strNum[0] == '-' ) ){
                if( allowSign && strNum.size() > 1 )
                    continue;
                else
                    return false;
            }
            
            if( strNum[i] > '9' || strNum[i] < '0' )
                return false;
        }
        
        return true;
    }
    
    bool isDecimalOrInteger(const string &strNum){
        int dotNum = findCharNum( strNum, '.' );
        if( dotNum > 1 )
            return false;
        
        if( dotNum == 0 )
            return isInteger(strNum);
        
        vector<string> strVector = splitString( strNum, '.' );
        if( strVector.size() == 0 )
            return false;
        else if( strVector.size() == 1 ){
            if( strNum[0] == '.' )
                return isInteger( strVector[0], false );
            else
                return isInteger( strVector[0], true );
        }
        else{
            bool valid1 = isInteger( strVector[0] );
            valid1 = valid1 || isSign( strVector[0][0] );
            bool valid2 = isInteger( strVector[1], false);
            return valid1 && valid2;
        }
        
        return true;
    }
    
    bool isSign( char c ){
        return c == '+' || c == '-';
    }
};
