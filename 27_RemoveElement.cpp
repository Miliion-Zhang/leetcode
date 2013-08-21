/** Remove Element
 * 
 * Given an array and a value, remove all instances of that value in place and return
 * the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the
 * new length.
 */

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if( n < 1 )
            return n;
        
        int frontIndex = 0;
        int backIndex = 0;
        while( frontIndex < n ){
            if( A[frontIndex] != elem ){
                A[backIndex] = A[frontIndex];
                backIndex++;
            }
            frontIndex++;
        }
        
        return backIndex;
    }
};
