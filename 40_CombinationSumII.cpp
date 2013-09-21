/** Combination Sum II

Given a collection of candidate numbers (C) and a target number (T), find all 
unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, ai , ak) must be in non-descending order.
(ie, a1 ? a2 ? ai ? ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > ret;
        
        sort(num.begin(), num.end());
        set<vector<int> > retSet = combinationSum(num, 0, target);
        
        for(set<vector<int> >::iterator it = retSet.begin(); it != retSet.end(); ++it)
            ret.push_back(*it);
        
        return ret;
    }
    
    set<vector<int> > combinationSum(vector<int> &candi, int curPos, int target){
        set<vector<int> > ret;
        if( target <= 0 || curPos >= candi.size() )
            return ret;
        
        for( int i = curPos; i < candi.size(); i++ ){
            if( candi[i] > target )
                break;
            
            
            if( candi[i] == target ){
                vector<int> hit;
                hit.push_back(candi[i]);
                ret.insert(hit);
            }
            else{
                set<vector<int> > subSet = combinationSum(candi, i+1, target-candi[i]);   // the only difference with question 39!
                if( subSet.empty() )
                    continue;
                
                for( set<vector<int>>::iterator it = subSet.begin(); it != subSet.end(); ++it ){
                    vector<int> hit;
                    hit.push_back(candi[i]);
                    appendToVector(hit, *it);
                    ret.insert(hit);
                }
            }
        }
        
        return ret;
    }
    
    void appendToVector(vector<int> &dst, const vector<int> &src){
        for( int i = 0; i < src.size(); i++ )
            dst.push_back( src[i] );
    }
};
