/** Gray Code

    The gray code is a binary numeral system where two successive values
    differ in only one bit.

    Given a non-negative integer n representing the total number of bits 
    in the code, print the sequence of gray code. A gray code sequence 
    must begin with 0.

    For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

    00 - 0
    01 - 1
    11 - 3
    10 - 2
    Note:
    For a given n, a gray code sequence is not uniquely defined.

    For example, [0,2,3,1] is also a valid gray code sequence according to 
    the above definition.

    For now, the judge is able to judge based on one instance of gray code
    sequence. Sorry about that.
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        if( n < 1 ){
            ret.push_back(0);
            return ret;
        }
        
        ret.push_back(0);
        ret.push_back(1);
        
        /**
         *  A simple way to generate Gray Code, e.g.:
         *  
         *  From 2bit Gray Code below to get 3bit Gray Code,
         *  00
         *  01
         *  11
         *  10
         *  Firstly, we need mirror the existing Gray Code,
         *  and add 0 as highest bit on top halt of them and
         *  1 on the lasts.
         *  00   ->   000
         *  01   ->   001
         *  11   ->   011
         *  10   ->   010
         *  10   ->   110
         *  11   ->   111
         *  01   ->   101
         *  00   ->   100
         */
        int bitWeight = 2;
        for( int i = 2; i <= n; i++ ){
            int size = ret.size();
            for( int j = size - 1; j >= 0; j-- ){
                ret.push_back( ret[j] + bitWeight );
            }
            bitWeight = bitWeight << 1;
        }
        
        return ret;        
    }
};
