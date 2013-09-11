/** Search Insert Position

Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if( n < 1 )
            return 0;
        else if( target < A[0] )
            return 0;
        else if( target > A[n-1] )
            return n;
        
        // should insert in the middle or will find it
        int lp = 0;
        int rp = n-1;
        while(1){
                        
            int mp = lp + (rp - lp) / 2;
            if( mp == lp ){ // the last one
                if( A[lp] == target )
                    return lp;
                else if( A[rp] == target )
                    return rp;
                else    // not found, shoud insert in the middle
                    return rp;
            }
            
            if( A[mp] == target )   // found it
                return mp;
            else if( A[mp] < target )   //search in right part
                lp = mp;
            else                        //search in left part
                rp = mp;
        }
        
    }
};
