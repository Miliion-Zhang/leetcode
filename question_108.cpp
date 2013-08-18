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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( num.size() < 1 )
            return NULL;
        
        int end = num.size();
        int rootPos = ( 0 + end ) / 2;
        TreeNode *root = new TreeNode( num[rootPos] );
        buildRootNode( root, 0, end, num );
        return root;
        
    }
    
    /**
     * Setting up the root node of a subtree, and bulid up it's subtree recursively.
     * @parameter root: the root node with `left` and `right` need to be updated.
     * @parameter begin: the begin position of this tree in vector, including this one.
     * @parameter end: the end position of this tree in vector, not including this one.
     */
    void buildRootNode(TreeNode *root, int begin, int end, vector<int> &num){
        if( begin >= end || begin < 0 )
            return;
        
        int rootPos = ( begin + end ) / 2;
        int leftSubSize = rootPos - begin;
        int rightSubSize = end - (rootPos+1);
        
        if( leftSubSize > 0 ){
            int leftSubRootPos = ( begin + rootPos ) / 2;
            TreeNode *leftSubRoot = new TreeNode( num[leftSubRootPos] );
            root->left = leftSubRoot;
            buildRootNode( leftSubRoot, begin, rootPos, num );
        }
        
        if( rightSubSize > 0 ){
            int rightSubRootPos = ( rootPos + 1 + end ) / 2;
            TreeNode *rightSubRoot = new TreeNode( num[rightSubRootPos] );
            root->right = rightSubRoot;
            buildRootNode( rightSubRoot, rootPos + 1, end, num );
        }
    }
};