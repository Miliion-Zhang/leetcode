/** Path Sum

	Given a binary tree and a sum, determine if the tree has a root-to-leaf path
	such that adding up all the values along the path equals the given sum.

	For example:
	Given the below binary tree and sum = 22,
				  5
				 / \
				4   8
			   /   / \
			  11  13  4
			 /  \      \
			7    2      1
	return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

*/


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