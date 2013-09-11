/** Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically 
next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible
order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding
outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int curPos = num.size() - 2;
        
        // from the tail to the head, find the postion that current value is less
        // than next value; and then find the least value among the values that
        // bigger than current value and at the right hand of current position;
        // then swap them, and filp the values in the right hand of current
        // position to get the minimum number.
        while( curPos >= 0 ){
            if( num[curPos] < num[curPos+1] ){
                int nextDigPos = curPos + 1;
                int p = curPos + 1;
                while( p < num.size() && num[p] > num[curPos] ){
                    nextDigPos = p;
                    p++;
                }
                
                swapNum(num, curPos, nextDigPos);
                flipNums(num, curPos+1, num.size()-1);
                
                break;
            }
            
            curPos--;
        }
        
        if( curPos < 0 ){   // not found next permutation
            flipNums(num, 0, num.size()-1);
        }
        
    }
    
    void swapNum(vector<int> &num, int p1, int p2){
        int tmp = num[p1];
        num[p1] = num[p2];
        num[p2] = tmp;
    }
    
    
    void flipNums(vector<int> &num, int start, int end){
        int lp = start;
        int rp = end;
        while( lp < rp ){
            swapNum(num, lp, rp);
            lp++;
            rp--;
        }
    }
};
