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
    int rootPosInPre;
    int beginPosInIn;   // including the node in position
    int endPosInIn;     // not including this one
    
    TreeInfo(TreeNode *root, int rootPos, int begin, int end){
        this->root = root;
        this->rootPosInPre = rootPos;
        this->beginPosInIn = begin;
        this->endPosInIn = end;
    }
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		// Check the given vectors
		int preSize = preorder.size();
        int inSize = inorder.size();
        if( preSize < 1 || inSize < 1 || preSize != inSize )
            return NULL;
        
		// Initialize root by the first element in preorder
        TreeNode *root = new TreeNode( preorder[0] );

		// subTreeQueue stores all informations of a subtree that will used to bulid it up.
		// Use queue simulate the recursion so that we can build the whole tree without using recursion.
        queue<TreeInfo *> subTreeQueue;
        TreeInfo *tree = new TreeInfo( root, 0, 0, inSize );
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
                int leftRootPosInPre = tree->rootPosInPre + 1;
                int leftRootVal = preorder[ leftRootPosInPre ];
                TreeNode *leftTree = new TreeNode( leftRootVal );
                tree->root->left = leftTree;
                
                subTreeQueue.push( new TreeInfo( leftTree, leftRootPosInPre, tree->beginPosInIn, treeRootPos ) );
            }
            
			// Do have right tree, set it up and add it to queue to be built in future
            if( rightTreeSize > 0 ){
                int rightRootPosInPre = tree->rootPosInPre + leftTreeSize + 1;
                int rightRootVal = preorder[ rightRootPosInPre ];
                TreeNode *rightTree = new TreeNode( rightRootVal );
                tree->root->right = rightTree;
                
                subTreeQueue.push( new TreeInfo( rightTree, rightRootPosInPre, treeRootPos+1, tree->endPosInIn ) );
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