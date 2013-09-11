/** String to Integer (atoi)

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, 
please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given 
input specs). You are responsible to gather all the input requirements up front.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until 
the first non-whitespace character is found. Then, starting from this character,
takes an optional initial plus or minus sign followed by as many numerical digits
as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral
number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral 
number, or if no such sequence exists because either str is empty or it contains
only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct
value is out of the range of representable values, INT_MAX (2147483647) or 
INT_MIN (-2147483648) is returned.
*/

class Solution {
public:
    int atoi(const char *str) {
        long long num = 0;
        bool isPos = true;
        
        int rp = 0; // read pointer, the index in str
        while( str[rp] == ' ' ){
            rp++;
        }
        
        if( isEnd(str, rp) )    // at the end
            return num;
        
        // check if exists plus or minus sign
        if( str[rp] == '+' || str[rp] == '-' ){
            isPos = (str[rp] == '+') ? true : false;
            rp++;
        }
        
        // the next char must be digital
        if( !isDigital( str[rp] ) )
            return num;
        
        bool isOverflow = false;
        num = getDigital(str[rp]);
        rp++;
        if( !isPos )
            num = -1 * num;
        while( isDigital(str[rp]) ){
            int dig = getDigital(str[rp]);
            if( isPos ){
                num = num * 10 + dig;
                if( num > INT_MAX ){
                    isOverflow = true;
                    break;
                }
            }
            else{
                num = num * 10 - dig;
                if( num < INT_MIN ){
                    isOverflow = true;
                    break;
                }
            }
            
            rp++;
        }
        
        if( isOverflow )
            return isPos ? INT_MAX : INT_MIN;
        else
            return num;
        
    }
    
    inline bool isEnd(const char *str, int rp){
        return str[rp] == '\0';
    }
    
    inline bool isDigital(const char c){
        return c <= '9' && c >= '0';
    }
    
    inline int getDigital(const char c){
        return int(c - '0');
    }
};
