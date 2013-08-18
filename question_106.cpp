/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeInfo {
    TreeNode *root;
    int rootPosInPost;
    int beginPosInIn;   // including the node in position
    int endPosInIn;     // not including this one
    
    TreeInfo(TreeNode *root, int rootPos, int begin, int end){
        this->root = root;
        this->rootPosInPost = rootPos;
        this->beginPosInIn = begin;
        this->endPosInIn = end;
    }
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
    	// Check the given vectors
		int postSize = postorder.size();
        int inSize = inorder.size();
        if( postSize < 1 || inSize < 1 || postSize != inSize )
            return NULL;
        
		// Initialize root by the last element in preorder
        TreeNode *root = new TreeNode( postorder[ postSize-1 ] );

		// subTreeQueue stores all informations of a subtree that will used to bulid it up.
		// Use queue simulate the recursion so that we can build the whole tree without using recursion.
        queue<TreeInfo *> subTreeQueue;
        TreeInfo *tree = new TreeInfo( root, postSize-1, 0, inSize );
        subTreeQueue.push( tree );
        
        while( !subTreeQueue.empty() ){
            // Get a new subtree from queue to be build
			tree = subTreeQueue.front();
            subTreeQueue.pop();
            
			// Find it's root value in `inorder` so that we can split it to left subtree and right subtree.
            int treeRootVal = tree->root->val;
            int treeRootPos = findPosInVector( treeRootVal, tree->beginPosInIn, tree->endPosInIn, inorder );
            
			// Calculate the subtree size, maybe zero, means having no subtree there.
            int leftTreeSize = treeRootPos - tree->beginPosInIn;
            int rightTreeSize = tree->endPosInIn - 1 - treeRootPos;
            
			// Do have left tree, set it up and add it to queue to be built in future
            if( leftTreeSize > 0 ){
                int leftRootPosInPost = tree->rootPosInPost - rightTreeSize - 1;
                int leftRootVal = postorder[ leftRootPosInPost ];
                TreeNode *leftTree = new TreeNode( leftRootVal );
                tree->root->left = leftTree;
                
                subTreeQueue.push( new TreeInfo( leftTree, leftRootPosInPost, tree->beginPosInIn, treeRootPos ) );
            }
            
			// Do have right tree, set it up and add it to queue to be built in future
            if( rightTreeSize > 0 ){
                int rightRootPosInPost = tree->rootPosInPost - 1;
                int rightRootVal = postorder[ rightRootPosInPost ];
                TreeNode *rightTree = new TreeNode( rightRootVal );
                tree->root->right = rightTree;
                
                subTreeQueue.push( new TreeInfo( rightTree, rightRootPosInPost, treeRootPos+1, tree->endPosInIn ) );
            }            
            
            // free the memory of queue
            delete tree;
            tree = NULL;
        }
        
        return root;
    }
    
    /**
     * Find the position of the given value in vector in range [begin, end).
     * Notice that the searching range is including the `begin` but `end`.
     */
    int findPosInVector(int value, int begin, int end, vector<int> &vec){
		// Make sure it will not out of range
        begin = ( begin < vec.size() ) ? begin : vec.size();
        end = ( end < vec.size() ) ? end : vec.size();

        for( int i = begin ; i < end ; i++ ){
            if( value == vec[i] )
                return i;
        }
        
        // Error, not find value in vec
        return -1;
    }
};