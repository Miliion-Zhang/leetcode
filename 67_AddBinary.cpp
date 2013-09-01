/** Add Binary

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*/

class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.size();
        int lenb = b.size();
        int maxLen = (lena > lenb)? lena : lenb;
        
        string ret;
        if( maxLen < 1 )
            return ret;
        
        string sumArray;
        char carry = '0';
        char s = '0';
        int pa = lena-1;
        int pb = lenb-1;
        for( int i = maxLen-1; i >= 0; i-- ){
            char ca = (pa >= 0) ? a[pa] : '0';
            char cb = (pb >= 0) ? b[pb] : '0';
            getSumCarry(ca, cb, s, carry);
            sumArray.push_back(s);
            pa--;
            pb--;
        }
        if( carry == '1' )
            sumArray.push_back('1');
        
        // Reverse sumArray to get ret
        for( int i = sumArray.size()-1; i >= 0; i-- ){
            ret.push_back( sumArray[i] );
        }
        
        return ret;
    }
    
    void getSumCarry(char a, char b, char &sum, char &carry){
        int num = 0;
        if( a == '1' )
            num++;
        if( b == '1' )
            num++;
        if( carry == '1' )
            num++;
        
        if( num == 0 ){
            sum = '0';
            carry = '0';
        }
        else if( num == 1 ){
            sum = '1';
            carry = '0';
        }
        else if( num == 2 ){
            sum = '0';
            carry = '1';
        }
        else{
            sum = '1';
            carry = '1';
        }
    }
};
