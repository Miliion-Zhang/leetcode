/**

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways
can you climb to the top?
*/

/**
  * This is a simple version, just need do some math and it's a simple combination
  * question.
  */
class Solution {
public:
    int climbStairs(int n) {
        int allNum = 0;
        
        int oneSteps = n;
        int twoSteps = 0;
        while( oneSteps >= 0 ){            
            allNum += combination( oneSteps + twoSteps, oneSteps );
            oneSteps -= 2;
            twoSteps += 1;
        }
        
        return allNum;
    }
    
    
    int combination(int n, int k){
        if(k==0 || n==k)
            return 1;
        if(2*k>n)
            k = n-k;
        
        // Here is some tricks, if use integer to calculate the answer directly,
        // it will works fine when n is small but will overflow and get the wrong
        // answer when n is larger than 35 even if use long.
        // So, use double to calculate and transform it to integer when should 
        // return the answer.
        double retf = 1;
        for(int i=0;i<k;++i) {
            retf *= n-i;
            retf /= i+1;
        }

        int ret = retf;
        return ret;
    }
};


/**
 * Here is my first version.
 * It will pass the small test cases but over time when run large cases.
 *
 * This solution is slow because it enumerate all possible distct ways and we
 * can output the exact steps when climbing the stairs.
 */
class Solution {
public:
    /**
     * It uses a stack to store each step when climbing.
     * If not climbe to top yet, then try to move 1 step;
     * If reach the top exactly, then it will be a valid way, and try to reverse;
     * If over the top, then must be a invalid way,  so just reverse;
     *
     * In reversing, pop the last step firstly, and then pop steps from stack
     * until find the step=1; then replace current top with 2, and go on searching.
     *
     * Note: If want to output the possible ways, just replace the stack with
     *          the array and use it as a stack, then we can output the valid ways
     *          in array every time we find it.
     */
    int climbStairs(int n) {
        int allNum = 0;
        stack<int> climbStack;
        
        int curSteps = 1;
        climbStack.push(1);
        while( !climbStack.empty() ){
            if( curSteps < n ){
                curSteps++;
                climbStack.push(1);
                continue;
            }
            
            if( curSteps == n ){
                allNum++;
            }
            
            curSteps -= climbStack.top();
            climbStack.pop();
            while( !climbStack.empty() && climbStack.top() == 2 ){
                curSteps -= climbStack.top();
                climbStack.pop();
            }
            
            if( !climbStack.empty() ){
                curSteps -= climbStack.top();
                climbStack.pop();
                curSteps += 2;
                climbStack.push(2);
            }
        }
        
        return allNum;
    }
};
