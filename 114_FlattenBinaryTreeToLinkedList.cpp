/** Flatten Binary Tree to Linked List

	Given a binary tree, flatten it to a linked list in-place.

	For example,
	Given

			 1
			/ \
		   2   5
		  / \   \
		 3   4   6
	The flattened tree should look like:
	   1
		\
		 2
		  \
		   3
			\
			 4
			  \
			   5
				\
				 6

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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        preorderFlatten( root );    
    }
    
    TreeNode *preorderFlatten(TreeNode *root){
        if(root == NULL)
            return NULL;
        
        TreeNode *leftLast = preorderFlatten( root->left );
        TreeNode *rightLast = preorderFlatten( root->right );
        if( leftLast != NULL ){
            TreeNode *right = root->right;
            root->right = root->left;
            root->left = NULL;
            if( rightLast != NULL )
                leftLast->right = right;
        }
        
        if( rightLast != NULL )
            return rightLast;
        else if( leftLast != NULL )
            return leftLast;
        else
            return root;
    }
};