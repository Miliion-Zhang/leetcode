/** Wildcard Matching

*/

class Solution {
public:
    /**
     * Non-recursive version.
     */
    bool isMatch(const char *s, const char *p) {  
        bool hasStar = false; // whether has '*' before or not
        const char *str = s;   // current position in s
        const char *ptr = p;  // current position in p
        while( *str != '\0' ){
            switch(*ptr){
                case '?':    // Move to next char
                    str++;
                    ptr++;
                    break;
                case '*':    // Remember current position, and then move ptr to next one and go on
                    hasStar = true;
                    s = str;
                    p = ptr;
                    while(*p == '*') p++;
                    if( *p == '\0' )
                        return true;
                    
                    str = s;
                    ptr = p;
                    break;
                default:   // Normal char, move to next position of str if match or 
                              // move to next position of s if not match and '*' exists.
                {
                    if( *str == *ptr ){
                        str++;
                        ptr++;
                    }
                    else{
                        if( !hasStar )
                            return false;
                        else{
                            s++;
                            str = s;
                            ptr = p;
                        }
                    }
                }
            }
        }
        
        while(*ptr == '*') ptr++;   // step over all '*' in ptr
        return (*ptr == '\0');
    }
      
};



/**
 * Another recursive version, but will exceed time limit
 */
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if( *s == '\0' ){
            if( *p == '\0' )
                return true;
            else if( *p == '*' ){
                while( *p == '*' ) p++;
                return (*p == '\0');
            }
            else
                return false;
        }
        
        while(*s){
            if(*p == '\0')
                return false;
            
            if( *p == '*' ){
                return isMatch(s, p+1) || isMatch(s+1, p);
            }
            else if( *p == '?' ){
                s++;
                p++;
            }
            else if( *s == *p ){
                s++;
                p++;
            }
            else
                return false;
        }        
        
        return isMatch(s, p);
        
    }
};