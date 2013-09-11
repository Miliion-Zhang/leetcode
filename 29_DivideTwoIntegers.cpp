/** Divide Two Integers

Divide two integers without using multiplication, division and mod operator.
*/

class Solution {
public:
    /**
     * Using a binary dividor method.
     * Which means simulate a binary dividor by determine every bit in quotient
     * from highest bit to lowest. Note that we use a lot of bit operator like <<
     * >> & | ~ to manipulate bits in integer
     */
    int divide(int dividend, int divisor) {
        // divide by 0?
        if( divisor == 0 )
            return 0;
        
        // dividend is 0
        if( dividend == 0 )
            return 0;
        
        int sign = (dividend > 0) ? 1 : -1;
        if( divisor > 0 ){
            sign = sign;
        }
        else{
            sign = 0 - sign;
        }
        
        unsigned int dvd = abs(dividend);
        unsigned int dvs = abs(divisor);
        unsigned int quo = 0;
        unsigned int one = 0x1;
        for( int i = 32; i >= 1; i-- ){
            unsigned int rem = (dvd >> (i-1));
            if( rem >= dvs ){
                quo = quo | ( one << (i-1) );
                rem -= dvs;
                dvd = ( ( dvd << (32+1-i) ) >> (32+1-i) );
                dvd += (rem << (i-1));
            }
            else{
                quo = quo & ( ~( one << (i-1) ) );
            }
        }
        
        if( sign >0 ){
            if( (quo & (one << 31)) == 1 ) //overflow
                return INT_MAX;
            else
                return int(quo);
        }
        else{
            if( (quo & (one << 31)) == 1 ) // overflow
                return INT_MIN;
            else
                return 0 - int(quo);
        }
    }
};
