/** 3Sum Closest

Given an array S of n integers, find three integers in S such that the sum is
closest to a given number, target. Return the sum of the three integers. You
may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        
        int closest = num[0] + num[1] + num[2];
        if( closest == target )
            return target;
        
        // searching like 3Sum
        for( int i = 0; i < num.size()-2; i++ ){
            int lp = i+1;
            int rp = num.size()-1;
            while(lp < rp){
                int sum = num[i] + num[lp] + num[rp];
                if( sum == target )// find the exact three sum!
                    return target;
                else if(  sum - target > 0 ) // should let sum be smaller
                    rp--;
                else if(  sum - target < 0) // should let sum be bigger
                    lp++;
                
                // if current sum is closer to target, then update the closest
                if( abs(closest - target) > abs(sum - target) ){
                    closest = sum;
                }
            }
        }
        
        return closest;
    }
};
