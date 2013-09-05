/** Permutation Sequence

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

class Solution {
public:
    /**
     * The permutation sequence is following a simple law, e.g.,
     * if n = 3, then all sequences are divided to 3 groups, because the number
     * of all sequences is 3!=6, then each group will have 2 sub-sequences.
     * Meanwhile, in each group, they will have same first char, and following the
     * order from low to high(1,2,3).
     * 
     * So if given n = 3, k = 4, we will know that the sequence will located in the
     * second group, and the first char is '2'; then can shrink the question to
     * n = 3-1 = 2, k = 4 - 2 * 1 =2, that is to say, the second sequence of '13'
     * can produce.
     *
     * When n = 2, there are 2!=2 all possible sequences and 2 groups, so in each
     * group only have one, and the first char of first group is '1', the first char of
     * second group is  '3'.
     */
    string getPermutation(int n, int k) {
        string permut;
        vector<int> candi;
        int num = 1;
        for( int i = 1; i <=n; i++ ){
            candi.push_back( i );
            num *= i;
        }
        
        for( int i = n; i >= 1; i-- ){
            num /= i;
            int group = (k-1) / num; 
            k = k - group * num;
            permut.push_back( char(candi[group]+'0') );
            candi.erase( candi.begin() + group );
        }
        
        return permut;
    }
};
