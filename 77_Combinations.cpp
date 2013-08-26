/** Combinations

Given two integers n and k, return all possible combinations of k numbers
out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/


class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        return combine(1, n, k);        
    }
    
    /**
     * Recursive version.
     * Divide it to two conditions:
     * 1) Select the last value in given range, then find all possible combinations
     *    excluding the last value and select k-1 from them.
     * 2) Do not select the last value, then find all possible combinations excluding
     *     the last value and select k from them.
     *
     * At the end, merge these combinations together and return them.
     */
    vector<vector<int>> combine(int begin, int end, int k){
        vector<vector<int>> ans;
        int size = end - begin + 1;
        if( begin > end || k < 1 || size < k )
            return ans;
        
        if( size == k ){
            vector<int> com(size,0);
            for( int i = 0; i < size; i++ )
                com[i] = i + begin;
            ans.push_back( com );
            return ans;
        }
        
        ans = combine( begin, end-1, k );        
        if( k == 1 ){
            vector<int> com(1, end);
            ans.push_back( com );
        }
        else{
            vector<vector<int>> sub = combine( begin, end-1, k-1 );
            for( int i = 0; i < sub.size(); i++ ){
                sub[i].push_back( end );
                ans.push_back( sub[i] );
            }
        }
        
        return ans;
    }
};