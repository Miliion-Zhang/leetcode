/** Subsets
	Given a set of distinct integers, S, return all possible subsets.

	Note:

	Elements in a subset must be in non-descending order.
	The solution set must not contain duplicate subsets.
	For example,
	If S = [1,2,3], a solution is:

	[
	  [3],
	  [1],
	  [2],
	  [1,2,3],
	  [1,3],
	  [2,3],
	  [1,2],
	  []
	]

*/

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ret;
        vector<int> empty;
        ret.push_back( empty );
        
        sort( S.begin(), S.end() );
        
        for( int x = 0; x < S.size(); x++ ){
            int lastSize = ret.size();
            for( int y = 0; y < lastSize; y++ ){
                vector<int> newSubsets( ret[y] );
                newSubsets.push_back( S[x] );
                
                ret.push_back( newSubsets );
            }            
        }
        
        return ret;
    }
};
