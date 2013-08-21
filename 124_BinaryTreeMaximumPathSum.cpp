/** Binary Tree Maximum Path Sum

    Given a binary tree, find the maximum path sum.

    The path may start and end at any node in the tree.

    For example:
    Given the below binary tree,

           1
          / \
         2   3
    
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
#include <limits.h>

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( root == NULL )
            return 0;
        
        int maxPathSum = INT_MIN;
        getMaxSinglePath( root, maxPathSum );
        return maxPathSum;        
    }
    
    int getMaxSinglePath(TreeNode *root, int &maxPathSum){
        if(root == NULL)
            return INT_MIN;
        
        int leftPath = getMaxSinglePath(root->left, maxPathSum);
        int rightPath = getMaxSinglePath(root->right, maxPathSum);
        
        // Find the max path between leftPath and rightPath
        int maxSinglePath = leftPath;
        if( rightPath > maxSinglePath )
            maxSinglePath = rightPath;
        
        // Update the max path by adding root's val to leftPath or rightPath
        if( root->val > 0 )
            maxSinglePath = maxSinglePath + root->val;
        
        // Check if the root's val only is the max.
        if( root->val > maxSinglePath )
            maxSinglePath = root->val;
        
        // Check if the leftPath + root + rightPath is the max
        leftPath = leftPath==INT_MIN ? 0 : leftPath;
        rightPath = rightPath==INT_MIN ? 0 : rightPath;
        int curPathSum = root->val + leftPath + rightPath ;

        if( maxSinglePath > curPathSum )
            curPathSum = maxSinglePath;
        
        // Update global maxPathSum
        if( curPathSum > maxPathSum )
            maxPathSum = curPathSum;
        
        
        maxSinglePath = (leftPath>rightPath ? leftPath : rightPath ) + root->val;
        return maxSinglePath > root->val ? maxSinglePath : root->val;
    }
};