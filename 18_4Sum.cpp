/** 4Sum

Given an array S of n integers, are there elements a, b, c, and d in S such that
a + b + c + d = target? Find all unique quadruplets in the array which gives
the sum of target.

Note:

Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ? b ? c ? d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        if( num.size() < 4 )
            return ret;
        
        //quick_sort(num, 0, num.size()-1);
        merge_sort(num);
        set<vector<int> > retSet;
        for( int p1 = 0; p1 <= num.size()-4; p1++ ){
            for( int p2 = p1+1; p2 <= num.size()-3; p2++ ){
                int smallTarget = target - num[p1] - num[p2];
                int p3 = p2 + 1;
                int p4 = num.size()-1;
                while( p3 < p4 ){
                    int sum = num[p3] + num[p4];
                    if( sum == smallTarget ){//find it!
                        vector<int> ans(4, 0);
                        ans[0] = num[p1];
                        ans[1] = num[p2];
                        ans[2] = num[p3];
                        ans[3] = num[p4];
                        retSet.insert( ans );
                        
                        p3++;
                        p4--;
                    }
                    else if( sum < smallTarget )
                        p3++;
                    else
                        p4--;
                }
            }
        }
        
        for(set<vector<int> >::iterator it=retSet.begin(); it!=retSet.end(); ++it){
            ret.push_back( *it );
        }
        
        return ret;
    }
 
//-----------------------------------------------------------------------------
// Quick sort
    /** 
     * Quick sort.
     * The lp/rp are the start index and last index in vector waiting to be sorted.
     */
    void quick_sort(vector<int> &num, int lp, int rp){
        if( lp < 0 || rp >= num.size() || lp >= rp )
            return;
        
        int i = lp-1;
        int j = lp;
        while( j < rp ){
            if( num[j] < num[rp] ){
                swap(num, i+1, j);
                i++;
                j++;
            }
            else
                j++;
        }
        
        swap(num, i+1, rp);
        quick_sort(num, lp, i);
        quick_sort(num, i+2, rp);
    }
    
    /**
     * Swap two elements in vector
     */
    inline void swap(vector<int> &num, int p1, int p2){
        if( p1 == p2 )
            return;
        
        int tmp = num[p1];
        num[p1] = num[p2];
        num[p2] = tmp;
    }

//-----------------------------------------------------------------------------
// Merge Sort
    
    void merge_sort(vector<int> &array){
        vector<int> tmp( array.size(), 0 );
        merge_sort( array, tmp, 0, array.size()-1 );
    }

    /**
     * Merge sort.
     * use tmp vector to merge two sections in array, so tmp should be the
     * same size with array, and lp / rp are the start index and last index in
     * array waiting to be sorted.
     */
    void merge_sort(vector<int> &array, vector<int> &tmp, int lp, int rp){
       if( lp >= rp )
           return;

       int mp = lp + (rp-lp)/2;
       merge_sort(array, tmp, lp, mp);
       merge_sort(array, tmp, mp+1, rp);
       merge(array, tmp, lp, mp, rp);
    }

    
     /**
     * Merge two sections of array together. p is the start index and r is the last
     * index, and q is the last one in 1st section.
     */
    void merge(vector<int> &array, vector<int> &tmp, int p, int q, int r){
        int lp = p;
        int rp = q+1;
        int i = p;
        // select the smaller one and copy to tmp each time
        while( lp <= q && rp <= r ){
            if( array[lp] < array[rp] ){
                tmp[i] = array[lp];
                lp++;
            }
            else{
                tmp[i] = array[rp];
                rp++;
            }
            i++;
        }
        
        // copy leftovers in 1st section
        while( lp <= q ){
            tmp[i] = array[lp];
            lp++;
            i++;
        }
        
        // copy leftovers in 2nd section
        while( rp <= r ){
            tmp[i] = array[rp];
            rp++;
            i++;
        }
        
        // copy elements from tmp back to array
        for( i = p; i <= r; i++ ){
            array[i] = tmp[i];
        }

    }

};