/** Jump Game II

Given an array of non-negative integers, you are initially positioned at the first
index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from
index 0 to 1, then 3 steps to the last index.)
*/

class Solution {
public:
    /**
      * Same way with question 55, using Greedy method and will cost O(n)
      * time and O(1) space.
      * Note: Each step, try to reach the farest point we can, so that more
      *           points are reachable. If can not reach the last one, then will
      *           return 0.
      */
    int jump(int A[], int n) {
        if( n < 2 )
            return 0;
        
        int steps = 0;
        int lastp = 0;
        int curp = 0;
        while(1){
            int nextp = 0;
            for( int i = lastp; i <= curp; i++ ){
                nextp = max(nextp, i+A[i]);
            }
            
            if( nextp >= n-1 ){
                steps++;
                break;
            }
            
             if( nextp <= curp ) {// can not go further, and not found
                steps = 0;
                break;
             }
            
            lastp = curp;
            curp = nextp;
            steps++;
        }
        
        return steps;
    }
};
