#include <cfloat>
class Solution {
public:
    double pow(double x, int n) {
        if( n == 0 )
            return 1.0;
        
        if( x == 1 )
            return 1.0;
        
        if( x == -1 ){
            if( n & 0x1 )
                return -1;
            else
                return 1;
        }
        
        bool nPos = true;   //true means positive and false means negetive
        if( n < 0 ){
            nPos = false;
            n = -n;
        }
        
        double product = 1;
        for( int i = 0; i < n; i++ ){
            product *= x;
            if( product == 0 )
                break;
        }
        
        if( nPos )
            return product;
        else{
            if( product == 0 )
                return 1E+37 ;  // I want to return DBL_MAX, but it told me not exists...
            else
                return 1.0 / product;
        }
        
    }
};
