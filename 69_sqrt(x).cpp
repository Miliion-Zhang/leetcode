/**  Sqrt(x)
Implement int sqrt(int x).

Compute and return the square root of x.
*/

/**
 * Much like binary search.
 * 
 * Note: Must use double to store the product of two 32 bit integers, otherwise
 *           it may be overflow even using long(because long is 32bit too).
 */
class Solution {
public:
    int sqrt(int x) {
        if( x < 0 )     //illegal
            return 0;
        
        if( x < 2 )     // 0 or 1
            return x;
        
        int large = x;
        int small = 0;
        while(1){
            int middle = small + (large - small)/2;
            if( middle == small )   // Done, find it
                return middle;
            
            double product = double(middle) * double(middle);
            if( product == double(x) )// Done, find it
                return middle;
            else if( product > double(x) )
                large = middle;
            else
                small = middle;
            
        }
    }
};
