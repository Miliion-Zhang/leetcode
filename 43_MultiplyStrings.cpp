/** Multiply Strings

Given two numbers represented as strings, return multiplication of the 
numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
Note: The num1 and num2 are in big endian. e.g., "123" means 123.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        string ret;
        
        // Reverse num1 and num2 to little endian
        string longNum;
        string shortNum;
        if( num1.size() > num2.size() ){
            longNum = reverseString(num1);
            shortNum = reverseString(num2);
        }
        else{
            longNum = reverseString(num1);
            shortNum = reverseString(num2);
        }
        
        // Do the multiplication one digital one by one.
        for( int i = 0; i < shortNum.size(); i++ ){
            string subProduct = multiply(longNum, atoi( shortNum[i] ), i);
            ret = add(ret, subProduct);
        }
        
        removeUselessZeros(ret);
        ret = reverseString(ret);   // Reverse product to big endian
        return ret;
    }
    
    /**
     * Reverse the given string.
     * Note: This is used to transform little endian to big endian or backwards.
     */
    string reverseString(const string &src){
        string ret;
        for( int i = src.size()-1; i >= 0; i-- )
            ret.push_back( src[i] );
        return ret;
    }
    
    /**
     * Remove the useless zeros in the high bits of number.
     * This only take effect when the product is zero, but here is a common function.
     */
    void removeUselessZeros(string &num){
        int size = num.size();
        if( num[size-1] == '0' ){
            // Notice: should leave one 0 if all digitals are 0.
            for( int i = size-1; i > 0; i-- ){
                if( num[i] != '0' )
                    break;
                num.pop_back();
            }
        }
        
    }
    
    /**
     * Get the product of string and one digital.
     * Note:
     *     (1) s is a large number represented as string, and
     *        the lower digital is located at front of string.
     *     (2) n is between 0 to 9
     *     (3) offset is the extra 0 in lower digital of product.
     * @return: the product represented as string and the lower
     *          digital is located at front of it.
     */
    string multiply(string s, int n, int offset){
        string product;
        for( int i = 0; i < offset; i++ )// add zeros in lower digitals
            product.push_back('0');
        
        int carry = 0;
        for( int i = 0; i < s.size(); i++ ){
            int subProduct = atoi(s[i]) * n + carry;
            
            carry = subProduct / 10;
            subProduct %= 10;
            product.push_back( itoa(subProduct) );
        }
        
        if( carry > 0 )
            product.push_back( itoa(carry) );
        
        return product;
    }
    
    /**
     * Get the sum of two numbers.
     * num1 and num2 are two numbers represented as strings,
     * and the lower digital is located at front of string.
     * e.g., "123'" stands for 321.
     */
    string add(string &num1, string &num2){
        string sum;
        int len1 = num1.size();
        int len2 = num2.size();
        int maxLen = (len1 > len2) ? len1 : len2;
        int carry = 0;
        for( int i = 0; i < maxLen; i++ ){
            char a = (i < len1) ? num1[i] : '0';
            char b = (i < len2) ? num2[i] : '0';
            int s = atoi(a) + atoi(b) + carry;
            
            if( s > 9 ){
                carry = 1;
                s -= 10;
            }
            else
                carry = 0;
            
            sum.push_back( itoa(s) );
        }
        
        if( carry == 1 )
            sum.push_back('1');
        
        return sum;
    }
    
    
    inline int atoi(char c){
        return int( c - '0' );
    }
    
    
    inline char itoa(int i){
        return char( i + '0' );
    }
};
