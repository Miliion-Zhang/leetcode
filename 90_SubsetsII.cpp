/** Subsets II
	Given a collection of integers that might contain duplicates, S, return all possible subsets.

	Note:

	Elements in a subset must be in non-descending order.
	The solution set must not contain duplicate subsets.
	For example,
	If S = [1,2,2], a solution is:

	[
	  [2],
	  [1],
	  [1,2,2],
	  [2,2],
	  [1,2],
	  []
	]

*/

#include <limits.h>

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ret;
        vector<int> empty;
        ret.push_back( empty );
        
        sort( S.begin(), S.end() );
        
        int lastVal = INT_MAX;	// Last value, for detecting duplicates 
        int dupNum = 0;			// duplicates' number
        
        for( int x = 0; x < S.size(); x++ ){
            int lastSize = ret.size();
            for( int y = 0; y < lastSize; y++ ){
				// if S[x] is duplicates, does not need to add new vector
				// which duplicates number of smaller or equal to dupNum.
				// This should avoid to add duplicates subsets to ret.
                if( S[x] == lastVal ){
                    int dupNumInVec = getDupNum( ret[y], S[x] );
                    if( dupNumInVec <= dupNum )
                        continue;
                }                    
                
                vector<int> newSubsets( ret[y] );
                newSubsets.push_back( S[x] );
                
                ret.push_back( newSubsets );
            }
            
            
            if( lastVal == S[x] )
                dupNum++;
            else
                dupNum = 0;
            
            lastVal = S[x];
        }
        
        return ret;
        
    }
    
	/**
     * Get the number of values in vec that equals to maxVal.
     * Note:
     *  1) The values in vec are always in non-descending order.
     *  2) The given maxVal never smaller than last value in vec.
     * 
     * So we don't need searching entire vec to find duplicates number,
     * just iterate each value from end of vec and break the loop right now
     * once not equal to maxVal.
     */
    int getDupNum(vector<int> &vec, int maxVal){
        int dupNum = 0;
        for( int i = vec.size()-1; i >= 0; i-- ){
            if( vec[i] != maxVal )
                break;
            dupNum++;
        }
        return dupNum;
    }
};