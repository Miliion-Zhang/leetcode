/** Remove Duplicates from Sorted Array II
 * 
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array A = [1,1,1,2,2,3],
 * 
 * Your function should return length = 5, and A is now [1,1,2,2,3].
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if( A == NULL || n < 3 ) // invalid or no duplicates exist
            return n;
        
        int dupNum = 0;
        int last = A[0];
        int frontIndex = 1;
        int backIndex = 1;
        
        while( frontIndex < n ){
            if( A[frontIndex] != last ){
                A[backIndex] = A[frontIndex];
                last = A[backIndex];
                frontIndex++;
                backIndex++;
                dupNum = 0;
            }
            else if( dupNum < 1 ){
                dupNum++;
                A[backIndex] = A[frontIndex];
                frontIndex++;
                backIndex++;
            }
            else{
                frontIndex++;
            }
        }
        
        return backIndex;
    }
};
