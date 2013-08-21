/** Balanced Binary Tree

	Given a binary tree, determine if it is height-balanced.

	For this problem, a height-balanced binary tree is defined as a binary tree
	in which the depth of the two subtrees of every node never differ by more 
	than 1.
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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        // Must initialize it to true
        bool isBalanced = true;
        dfs( root, isBalanced );
        return isBalanced;
    }
    
    /**
     * Get the height of the given node by DFS.
     * If the given node is not balanced, then mark it and break the following DFS.
     */ 
    int dfs(TreeNode *root, bool &isBalanced){
        if( root==NULL )
            return 0;
        
        if( !isBalanced )
            return 0;
        
        // Leaf node
        if( root->left == NULL && root->right == NULL )
            return 1;
        
        // Get the height of subtrees
        int hleft = dfs( root->left, isBalanced );
        int hright = dfs( root->right, isBalanced );
        
        // Not balanced, mark it to break the checking process.
        if( abs( hleft - hright ) > 1 ){
            isBalanced = false;
            return 0;
        }
        
        // Return the height of this node
        if( hleft > hright )
            return hleft + 1;
        else
            return hright + 1;
    }
};