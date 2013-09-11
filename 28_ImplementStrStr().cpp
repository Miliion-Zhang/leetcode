/** Implement strStr()

Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle
is not part of haystack.
*/

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if( haystack == NULL || needle == NULL )
            return NULL;
        
        if( *needle == '\0' ){
            return haystack;
        }
        
        char *cur = haystack;
        char *curAdv = haystack;
        char *p2 = needle;
        while( *++p2 )
            curAdv++;
        
        while( *curAdv != '\0' ){
            if( cur == needle )
                return cur;
            
            bool found = false;
            char *hp = cur;
            char *np = needle;
            while(1){
                if( *np == '\0' ){
                    found = true;
                    break;
                }
                
                if( *hp != *np || *hp == '\0' ){
                    found = false;
                    break;
                }
                
                hp++;
                np++;
            }
            
            if( found )
                return cur;
            cur++;
            curAdv++;
        }
        
        return NULL;
    }
};
