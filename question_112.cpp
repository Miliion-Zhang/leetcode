/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool hasOne = false;
        return dfs( root, 0, sum, hasOne);
        
    }
    
    
    bool dfs(TreeNode *root, int curSum, int &wantSum, bool &hasOne){
        if( root == NULL )
            return false;
        
        // Cut off unnessary search
        if( hasOne )
            return true;
        
        // Update curSum
        curSum += root->val;
        
        // Leaf node, check if condition matched
        if( root->left == NULL && root->right == NULL ){
            if( curSum == wantSum ){
                hasOne = true;
                return true;
            }
            else
                return false;
        }
        
        // Continue to search leaf node
        return dfs( root->left, curSum, wantSum, hasOne ) ||
               dfs( root->right, curSum, wantSum, hasOne ) ;
        
    }
};