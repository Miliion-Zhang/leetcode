/** Sum Root to Leaf Numbers

    Given a binary tree containing digits from 0-9 only, each root-to-leaf path
    could represent a number.

    An example is the root-to-leaf path 1->2->3 which represents the number 123.

    Find the total sum of all root-to-leaf numbers.

    For example,

        1
       / \
      2   3
    The root-to-leaf path 1->2 represents the number 12.
    The root-to-leaf path 1->3 represents the number 13.

    Return the sum = 12 + 13 = 25.

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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
        dfs( root, 0, sum );
        return sum;
        
    }
    
    void dfs(TreeNode *root, int value, int &sum){
        if( root == NULL )
            return;
        
        // Update value
        value = value * 10 + root->val;
        
        // Leaf node, add to sum and return
        if( root->left == NULL && root->right == NULL ){
            sum += value;
            return;
        }
        
        // Continue to search leaf node
        dfs( root->left, value, sum );
        dfs( root->right, value, sum );
    }
};