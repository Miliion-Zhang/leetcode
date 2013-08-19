class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string filtered;
        filterString( s, filtered );
        int size = filtered.size();
        
        if( size < 1 )
            return true;
        
        int i = 0, j = size - 1;
        while( i < j ){
            if( filtered[i] != filtered[j] )
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    /**
     * Filter the source string to get only alphanumeric characters
     * and transform to lowercase.
     */
    void filterString(string &src, string &filtered){
        int size = src.size();
        for(int i=0 ; i<size ; i++){
            char c = src[i];
            if( isAlphaNum(c) ){
                filtered.push_back( toLower(c) );
            }            
        }
    }
    
    inline bool isAlphaNum(char c){
        return ( c >= 'A' && c <= 'Z' )
             ||( c >= 'a' && c <= 'z' )
             ||( c >= '0' && c <= '9' );
    }
    
    inline char toLower(char c){
        if( c >= 'A' && c <= 'Z' )
            return c + ('a' - 'A');
        else
            return c;
    }
};
