/** Merge Sorted Array

    Given two sorted integer arrays A and B, merge B into A as one sorted array.

    Note:
    You may assume that A has enough space to hold additional elements 
    from B. The number of elements initialized in A and B are m and n respectively.
*/


class Solution {
public:
    /**
      * This question is a little more difficult than merge sorted list because
      * when insert a element in an array, we have to move all elements in array
      * behind it backwards by one step. This can be time-consuming.
      * So rather than move them every time, I prefer to move all items in A 
      * backwards n step in advance to leave space for merging B.
      *
      * This solution will take O(m+n) time and O(1) extra space.
      */
    void merge(int A[], int m, int B[], int n) {
        if( n < 1 )
            return;
        
        if( m < 1 ){
            memcpy( A, B, sizeof(int) * n );
            return;
        }
        
        // Right shift all items in A by n step to leave empty space 
        // for merging with B.
        for( int i = m - 1; i >= 0 ; i-- )
            A[ i + n ] = A[i];
        
        int wp = 0;     // Write position in A
        int rpa = n;    // Read position in A
        int rpb = 0;    // Read position in B
        while(1){
            // All merged: all items have been written or finished B
            if( wp >= m+n || rpb >= n )
                break;
            
            if( rpa >= m+n || A[rpa] >= B[rpb] ){  // Select a element from B
                A[wp] = B[rpb];
                rpb++;
            }
            else {													  // Select a element from A
                A[wp] = A[rpa];
                rpa++;
            }
            wp++;
        }
        
    }
};