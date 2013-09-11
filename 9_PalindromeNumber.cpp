/** Palindrome Number

Determine whether an integer is a palindrome. Do this without extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction
of using extra space.

You could also try reversing an integer. However, if you have solved the 
problem "Reverse Integer", you know that the reversed integer might overflow.
How would you handle such case?

There is a more generic way of solving this problem.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0 )
            return false;
        else if( x < 10 )
            return true;
        
        int factor = 1;
        while( x / factor >= 10 )
            factor *= 10;
        
        while( factor >= 10 ){
            int highDig = x / factor;
            x = x % factor;
            int lowDig = x % 10;
            x = x / 10;
            
            if( highDig != lowDig )
                return false;
            
            factor /= 100;
        }
        
        return true;
    }
};
