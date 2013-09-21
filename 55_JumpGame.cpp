/** Jump Game

Given an array of non-negative integers, you are initially positioned at the first
index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:
    /**
     * Greedy Method.
     * Because at position i, it will have maximum jump length of A[i], so from
     * i to i+A[i] are reachable, then only need find next maximum positon we
     * can reach at each point i to i+A[i], and go on unitil reaching last one or
     * can not go any further.
     * So will cost O(n) time and O(1) space.
     */
    bool canJump(int A[], int n) {
        if( n < 2 )
            return true;
                
        int lastp = 0;
        int curp = 0;
        while(1){
            int nextp = 0;
            for( int i = lastp; i <= curp; i++ )
                nextp = max(nextp, i+A[i]);
            
            if( nextp >= n-1 )
                return true;
            
            if( nextp <= curp ) // can not go further, and not found
                break;
            
            lastp = curp;
            curp = nextp;
        }
        
        return false;
    }
    
    
    /**
      * The first version, using DP method and recursive style, but will exceed
      * time limit.
      */
    bool canJump(int A[], bool canReach[], int n, int curPos){
        if( curPos >= n )   // out of range
            return false;
        if( curPos == n-1 ) // reach last postion
            return true;
        if( !canReach[curPos] ) // can not reach from current position
            return false;
        
        int curMaxStep = A[curPos];
        if( curMaxStep < 1 ){
            canReach[curPos] = false;
            return false;
        }
        
        bool can = false;
        for( int i = 1; i <= curMaxStep; i++ ){
            can = can || canJump(A, canReach, n, curPos + i);
            if( can )
                break;
        }
        
        if( can )
            return true;
        else{
            canReach[curPos] = false;
            return false;
        }
    }
};
