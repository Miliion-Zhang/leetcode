/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <limit.h>

class Solution {
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int minDepth = INT_MAX;
        
        if( root == NULL )
            return 0;
        
        dfs( root, 1, minDepth );
        return minDepth;
        
    }
    
    void dfs(TreeNode *root, int curDepth, int &minDepth){
        if( root == NULL )
            return;
        
        // Cut off unnecessary search path
        if( curDepth >= minDepth )
            return;
        
        // Leaf node, and depth smaller than minDepth
        if( root->left == NULL && root->right == NULL ){
            minDepth = curDepth;
            return;
        }
        
        // Continue to search
        dfs( root->left, curDepth + 1, minDepth );
        dfs( root->right, curDepth + 1, minDepth );
    }
};