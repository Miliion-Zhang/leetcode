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
