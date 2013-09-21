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


/** 
 * Optimize solution, using quick sort and then can find the pair in O(n) time,
 * but the all time is O(n*logn) due to quick sort.
 */
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        if( numbers.size() < 2 )
            return ret;
        
        vector<int> copied(numbers);
        
        sort(copied, 0, copied.size()-1);
        int p1 = 0;
        int p2 = copied.size()-1;
        bool found = false;
        while( p1 < p2 ){
            int sum  = copied[p1] + copied[p2];
            if( sum == target ){
                found = true;
                break;
            }
            else if( sum < target )
                p1++;
            else
                p2--;
        }
        
        if( found ){
            for( int i = 0; i < numbers.size(); i++ ){
                if( numbers[i] == copied[p1] || numbers[i] == copied[p2] )
                    ret.push_back(i+1);
                else if( ret.size()==2 )
                    break;
            }
            
            if( ret[0] > ret[1] )
                swap(ret, 0, 1);
        }
        
        return ret;
    }
    
    void sort(vector<int> &numbers, int lp, int rp){
        if( lp < 0 || rp >= numbers.size() || lp >= rp )
            return;
        
        int i = lp-1;
        int j = lp;
        while( j < rp ){
            if( numbers[j] >= numbers[rp] )
                j++;
            else{
                swap(numbers, i+1, j);
                i++;
                j++;
            }
        }
        
        swap(numbers, i+1, rp);
        sort(numbers, lp, i);
        sort(numbers, i+2, rp);
    }
    
    inline void swap(vector<int> &numbers, int p1, int p2){
        if( p1 == p2 )
            return;
        int tmp = numbers[p1];
        numbers[p1] = numbers[p2];
        numbers[p2] = tmp;
    }
};
