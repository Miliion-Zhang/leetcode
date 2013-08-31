/** Restore IP Addresses

Given a string containing only digits, restore it by returning all possible
valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        if( s.size() < 4 )  // Not valid IP Address
            return ret;
        
        // Enumerate all possible position of three dots
        // @note: we define the dot position as the index(from 0) 
        //        in s where we want to insert a dot.
        //        e.g., p1=2, mean we should insert a dot between s[1] and s[2]
        
        // First dot's position
        for( int i = 1; i < 4; i++ ){
            bool valid1 = isValidDigital(s, 0, i);
            if( !valid1 )   // cut unessary search
                continue;
            
            // Second dot's position
            for( int j = i + 1; j < i + 4; j++ ){
                if( j >= s.size() )
                    break;
                
                bool valid2 = isValidDigital(s, i, j);
                if( !valid2 )   // cut unessary search
                    continue;
                
                // Third dot's position
                for( int k = j + 1; k < j +4; k++ ){
                    if( k > s.size() )
                        break;
                    
                    // Add valid IP address to ret.
                    bool valid3 = isValidDigital(s, j, k);
                    bool valid4 = isValidDigital(s, k, s.size() );
                    if( valid3 && valid4 )
                        ret.push_back( generateIP(s, i, j, k) );
                    
                }
            }
        }
        
        return ret;
    }
    
    /**
     * Check if the substring is valid ip digital or not.
     * Note: including the char of index 'begin', but not include
     *       the char of index 'end'.
     */
    bool isValidDigital(const string &s, int begin, int end){
        //Note: should '012' be valid? currently is not valid
        
        if( end <= begin || end - begin > 3 ) // too short or too long
            return false;
        
        // not alow '012' or '00', but '0' is valid
        if( s[begin] == '0' && end-begin > 1 )
            return false;
        
        // convert to integer, must be valid digital and smaller than 256
        int dig = 0;
        for( int i = begin; i < end; i++ ){
            int n = int( s[i] - '0' );
            if( n < 0 || n > 9 )
                return false;
            
            dig *= 10;
            dig += n;
        }
        
        return dig < 256;
    }
    
    /**
     * Generate a IP address from given s and dot positions.
     * @note: each position is the index in s where we want to insert a dot.
     *        e.g., p1=2, mean we should insert a dot between s[1] and s[2]
     */
    string generateIP(const string &s, int p1, int p2, int p3){
        string ip;
        for( int i = 0; i < s.size(); i++ ){
            ip.push_back( s[i] );
            if( i == p1-1 || i == p2-1 || i == p3-1 ){
                ip.push_back( '.' );
            }
        }
        return ip;
    }
};
