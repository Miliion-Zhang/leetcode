/** Plus One

Given a number represented as an array of digits, plus one to the number.

Note:
    1) The lower digital in the number is located in the back of array.
       e.g., [2,9,3] means 293.
*/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> ret;
        if( digits.size() < 1 )
            return ret;
        
        vector<int> sumDigs;
        int carry = 1;  // Initialize with 1, to add one.
        for( int i = digits.size()-1; i >= 0; i-- ){
            int sum = digits[i] + carry;
            if( sum > 9 ){
                carry = 1;
                sum -= 10;
            }
            else
                carry = 0;
            
            sumDigs.push_back(sum);
        }
        if( carry == 1 )
            sumDigs.push_back(1);
        
        // Reverse sumDigs to ret
        for( int i = sumDigs.size()-1; i >= 0; i-- ){
            ret.push_back( sumDigs[i] );
        }
        
        return ret;
    }
};
