class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if( n < 2 )
            return n;
        
        int last = A[0];
        int frontIndex = 1;
        int backIndex = 1;
        while( frontIndex < n ){
            if( A[frontIndex] != last ){
                A[backIndex] = A[frontIndex];
                last = A[backIndex];
                frontIndex++;
                backIndex++;
                continue;
            }
            
            frontIndex++;
        }       
            
        return backIndex;
    }
};
