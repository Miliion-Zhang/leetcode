/** Unique Binary Search Trees
    Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

    For example,
    Given n = 3, there are a total of 5 unique BST's.

       1         3     3      2      1
        \       /     /      / \      \
         3     2     1      1   3      2
        /     /       \                 \
       2     1         2                 3
	
	采用动态规划的方法，dp数组的含义是，给定个数为 i 的连续整数，这 i 个数能形成的有效BST个数
	为dp[i]，i=0 时表示空树。初始化dp为：
    dp[0] = 1; dp[1] = 1;
    
    dp[n] =  1) n作为根结点，之前的二叉树就是left.child 这种情况： dp[n-1]*dp[0]
				 2) n-1 是根结点，那么 n只有一种情况 ： dp[n-2] * dp[1]
                 3) n-2 是根节点，right tree: dp[2] * left child : dp[n -3]
                 ...
                 n) 1 是根结点：dp[0] * dp[n-1]
    dp[n] = sigma{i = 0..n-1} dp[i]*dp[n-1-i]
    
    其实就是说白了考虑左右子tree的大小就ok，因为大小暗含了这个时候根结点的情况，所以和枚举根结点从1...n是一样的
    */

class Solution {
public:
    int numTrees(int n) {
        if( n < 1 )
            return 0;
        
        if( n == 1 )
            return 1;
        
        int *dp = new int[ n+2 ];
        memset( dp, 0, sizeof(int) * (n+2) );
        dp[0] = dp[1] = 1;
        
        for( int m = 2 ; m <=n ; m++ ){
            for( int i = m ; i > 0 ; i-- ){
                dp[m] += dp[i-1] * dp[m-i];
            }
        }
        
        int allNum = dp[n];
        delete dp;
        return allNum;
    }
};
