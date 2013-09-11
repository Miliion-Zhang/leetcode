/** Search for a Range

Given a sorted array of integers, find the starting and ending position of a
given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret(2, -1);
        if( A == NULL || n < 1 )
            return ret;
        
        int lp = 0;
        int rp = n-1;
        while(1){
            if( lp > rp )
                break;
            
            if( lp == rp ){
                if( A[lp] == A[rp] ){// found it
                    findEdge(A, n, target, lp, ret);                    
                }                
                break;
            }
            
            int mp = lp + (rp-lp)/2;
            if( A[mp] == target ){  // found it
                findEdge(A, n, target, mp, ret);
                break;
            }
            else if( A[mp] > target )   // search left part
                rp = mp-1;
            else                        // search right part
                lp = mp+1;
        }
        
        return ret;
        
    }
    
    void findEdge(int A[], int n, int target, int pos, vector<int> &range){
        if( pos < 0 || pos >= n )
            return;
        
        if( A[pos] != target )
            return;
        
        int lp = pos;
        while( lp >= 0 && A[lp] == target ){
            range[0] = lp;
            lp--;
        }
        
        int rp = pos;
        while( rp < n && A[rp] == target ){
            range[1] = rp;
            rp++;
        }
    }
};
