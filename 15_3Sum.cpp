/** 3Sum

Given an array S of n integers, are there elements a, b, c in S such tha
t a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ? b ? c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        if( num.size() < 3 )
            return ret;
        
        sort(num.begin(), num.end());
        for( int i = 0; i < num.size()-2; i++ ){
            int sum = -num[i];
            int lp = i+1;
            int rp = num.size()-1;
            while( lp < rp ){
                if( num[lp] + num[rp] == sum ){
                    vector<int> three(3,0);
                    three[0] = num[i];
                    three[1] = num[lp];
                    three[2] = num[rp];
                    
                    if( !isInVector(ret, three) )
                        ret.push_back( three );
                    
                    lp++;
                    rp--;
                }
                else if( num[lp] + num[rp] > sum )
                    rp--;
                else
                    lp++;
            }
        }
        
        return ret;        
    }
    
    inline bool isInVector(vector<vector<int> > &ret, vector<int> &three){
        if( ret.empty() )
            return false;
        
        for( int i = 0; i < ret.size(); i++ ){
            if( isSameThreeSum(ret[i], three) )
                return true;
        }
        
        return false;
    }
    
    inline bool isSameThreeSum(vector<int> &three1, vector<int> &three2){
        if( three1.size() != 3 || three2.size() != 3 ){
            return false;
        }
        
        return three1[0] == three2[0]
            && three1[1] == three2[1]
            && three1[2] == three2[2];
    }
};
