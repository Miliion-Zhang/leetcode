/** Two Sum

    Given an array of integers, find two numbers such that they add up to a 
    specific target number.

    The function twoSum should return indices of the two numbers such that 
    they add up to the target, where index1 must be less than index2. Please
    note that your returned answers (both index1 and index2) are not zero-based.

    You may assume that each input would have exactly one solution.

    Input: numbers={2, 7, 11, 15}, target=9
    Output: index1=1, index2=2
*/


class Solution {
public:
    /**
     * Currently is a simple version that takes O(n*n) time.
     * 
     * But can reduced to O(n*logn) by sorting the given vector,
     * and when iterate each element in it, only need to find whether
     * the wantVal = target-currentVal is in vector or not( This procedure
     * can be done by using binary search and takes O(logn) time).
     * So the optimized version will take O(n*logn) time.
     */

    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        int size = numbers.size();
        for( int i = 0; i < size - 1; i++ ){
            for( int j = i+1; j < size; j++ ){
                if( numbers[i] + numbers[j] == target ){
                    ret.push_back( i+1 );
                    ret.push_back( j+1 );
                    break;
                }
            }
        }
        
        return ret;
    }
};
