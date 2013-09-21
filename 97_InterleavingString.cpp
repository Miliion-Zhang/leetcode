/** Interleaving String

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

/** 
 * 二维DP问题.
 
对于
s1 = a1, a2 ........a(i-1), ai
s2 = b1, b2, .......b(j-1), bj
s3 = c1, c3, .......c(i+j-1), c(i+j)

定义 match[i][j] 意味着，S1的(0, i)和S2的(0,j)，匹配与S3的(i+j)
如果 ai == c(i+j), 那么 match[i][j] = match[i-1][j]， 等价于如下字符串是否匹配。

s1 = a1, a2 ........a(i-1)
s2 = b1, b2, .......b(j-1), bj
s3 = c1, c3, .......c(i+j-1)

同理，如果bj = c(i+j), 那么match[i][j] = match[i][j-1];

所以，转移方程如下：
Match[i][j]
    =   (s3.lastChar == s1.lastChar) && Match[i-1][j]
      ||(s3.lastChar == s2.lastChar) && Match[i][j-1]
初始条件：
    i=0 && j=0时，Match[0][0] = true;
    i=0时， s3[j] = s2[j], Match[0][j] |= Match[0][j-1]
           s3[j] != s2[j], Match[0][j] = false;

    j=0时， s3[i] = s1[i], Match[i][0] |= Match[i-1][0]
           s3[i] != s1[i], Match[i][0] = false;
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size() )
            return false;
        
        vector<vector<bool> > match(s1.size()+1, vector<bool>(s2.size()+1, false));
        match[0][0] = true;
        for( int j = 1; j < match[0].size(); j++ ){ // initialize first row
            if( s2[j-1] == s3[j-1] )
                match[0][j] = match[0][j-1];
            else
                match[0][j] = false;
        }
        
        for( int i = 1; i < match.size(); i++ ){ // initialize first column
            if( s1[i-1] == s3[i-1] )
                match[i][0] = match[i-1][0];
            else
                match[i][0] = false;
        }
        
        for( int i = 1; i < match.size(); i++ ){ // update match  row by row
            for( int j = 1; j < match[0].size(); j++ ){
                if( s1[i-1] == s3[i+j-1] )
                    match[i][j] = match[i][j] || match[i-1][j];
                
                if( s2[j-1] == s3[i+j-1] )
                    match[i][j] = match[i][j] || match[i][j-1];
            }
        }
        
        return match[s1.size()][s2.size()];
    }
};
