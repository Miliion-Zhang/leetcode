/** Binary Tree Inorder Traversal
	Given a binary tree, return the inorder traversal of its nodes' values.

	For example:
	Given binary tree {1,#,2,3},

	   1
		\
		 2
		/
	   3
	return [1,3,2].

	Note: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> inorder;
        
        if( root == NULL )
            return inorder;
        
        stack<TreeNode *> nodeStack;
        
        TreeNode *curNode = root;
        while( true ){
            // If curNode is not null, then push current node to stack,
            // and then visit left child first.
            if( curNode ){
                nodeStack.push( curNode );
                curNode = curNode->left;
                continue;
            }
                                
            // pop one from stack, visit it and then it's right children
            if( nodeStack.empty() )
                break;
            curNode = nodeStack.top();
            nodeStack.pop();
            
            inorder.push_back( curNode->val );
            
            curNode = curNode->right;
        }
        
        return inorder;
    }
};