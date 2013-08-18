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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxDepth = 0;
        dfs( root, 0, maxDepth );
        return maxDepth;
        
    }
    
    void dfs(TreeNode *root, int curDepth, int &maxDepth){
        if( root == NULL )
            return;
        
        // Update the depth from root to current node
        curDepth += 1;
        
        // Leaf node
        if( root->left == NULL && root->right == NULL ){
            if( curDepth > maxDepth )
                maxDepth = curDepth;
            return;
        }
        
        // Continue to search
        dfs( root->left, curDepth, maxDepth );
        dfs( root->right, curDepth, maxDepth );
    }
};