/** Path Sum II

	Given a binary tree and a sum, find all root-to-leaf paths where each path's
	sum equals the given sum.

	For example:
	Given the below binary tree and sum = 22,
				  5
				 / \
				4   8
			   /   / \
			  11  13  4
			 /  \    / \
			7    2  5   1
	return

	[
	   [5,4,11,2],
	   [5,8,4,5]
	]

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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> curPath;
        vector<vector<int> > ans;
        
        dfs( root, 0, sum, curPath, ans );
        return ans;
        
    }
    
    void dfs(TreeNode *root, int curSum, int &wantSum,
            vector<int> &curPath, vector<vector<int> > &ans){
        if( root == NULL )
            return;
        
        // Update curSum / curPath
        curSum += root->val;
        curPath.push_back( root->val );
        
        // Leaf node, check if condition is met
        if( root->left == NULL && root->right == NULL ){
            if( curSum == wantSum ){
                copyPath2ans( curPath, ans );
            }
            
            curPath.pop_back();
            return;
        }
        
        // Continue to search
        dfs( root->left, curSum, wantSum, curPath, ans );
        dfs( root->right, curSum, wantSum, curPath, ans );
        
        curPath.pop_back();
        return;
        
    }
    
    void copyPath2ans( const vector<int> &src, vector<vector<int> > &target ){
        vector<int> newVec;
        for( int i=0; i < src.size(); i++ ){
            newVec.push_back( src[i] );
        }
        
        target.push_back( newVec );        
    }
};