/** Unique Binary Search Trees
    Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

	For example,
	Given n = 3, your program should return all 5 unique BST's shown below.

	   1         3     3      2      1
		\       /     /      / \      \
		 3     2     1      1   3      2
		/     /       \                 \
	   2     1         2                 3
	
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
    vector<TreeNode *> generateTrees(int n) {
        
        return generateTrees(1, n);        
    }
    
    vector<TreeNode *> generateTrees(int startval, int endval){
        vector<TreeNode *> ret;
        if( startval > endval ){    // only valid startval and endval
            ret.push_back( NULL );
            return ret;
        }
        
        // For each value as root, get it's left subtrees and right subtrees,
        // and then combine them to build up a new tree.
        for( int rootval = startval; rootval <= endval; rootval++ ){
            vector<TreeNode *> leftTrees = generateTrees(startval, rootval - 1);
            vector<TreeNode *> rightTrees = generateTrees(rootval + 1, endval);
            
            /**
             * Building up new trees using leftTrees and rightTrees, the numbers is
             * m*n where m is size of leftTrees and n is rightTrees.
             * 
             * Note : 
             *      1) Should copy subtrees in leftTrees/rightTrees other than point
             *         to it directly.
             *      2) Here is a little more fussy, because all new trees are copied
             *         from leftTrees/rightTrees, we need to release the memory of BST
             *         in leftTrees/rightTrees.
             */
            for(int x = 0; x < leftTrees.size(); x++){
                for(int y = 0; y < rightTrees.size(); y++){
                    TreeNode *root = new TreeNode( rootval );
                    root->left = copyTrees( leftTrees[x] );
                    root->right = copyTrees( rightTrees[y] );
                    ret.push_back( root );
                }
            }            
            
            // Release leftTrees and rightTrees
            for(int i=0; i < leftTrees.size(); i++)
                freeTrees( leftTrees[i] );
            for(int i=0; i < rightTrees.size(); i++)
                freeTrees( rightTrees[i] );
        }
        
        return ret;
    }
    
    /**
     * Copy a tree recursively to get a new one.
     */
    TreeNode *copyTrees(const TreeNode *src){
        if( src == NULL )
            return NULL;
        
        TreeNode *root = new TreeNode( src->val );
        TreeNode *left = copyTrees( src->left );
        TreeNode *right = copyTrees( src->right );
        root->left = left;
        root->right = right;
        return root;
    }
    
    /**
     * Delete a tree recursively.
     */
    void freeTrees(const TreeNode *root){
        if( root == NULL )
            return;
        
        freeTrees( root->left );
        freeTrees( root->right );
        delete root;
    }
};
