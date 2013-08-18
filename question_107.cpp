/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

using namespace std;
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        // The number of node that current level has.
        int curLevelNodesNum = 0;
        // The number of node that next level has.
        int nextLevelNodesNum = 0;
        
        // Store the final answer
        vector<vector<int> > treeTraversal;
        
        // Queue for bfs
        queue<TreeNode *> nodeQueue;
        
        if( root == NULL )
            return treeTraversal;
        
        list<vector<int>> levelValuesList;  // a list to store every level's value vector.
        int nodeNum = 0;
        curLevelNodesNum = 1;
        nextLevelNodesNum = 0;
        vector<int> *curLevelValues = NULL;
        nodeQueue.push( root );
        while( curLevelNodesNum > 0 ){
            // construct a vector to store values of current level nodes.
            if( nodeNum == 0 ){
                // a little optimization for vector by initializing it with capacity.
                curLevelValues = new vector<int>( curLevelNodesNum );
            }
            
            // Get a node from queue, add it's value to curLevelValues, and push it's childrens to queue.
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();
            (*curLevelValues)[nodeNum] = node->val;
            
            if( node->left != NULL ){
                nodeQueue.push( node->left );
                nextLevelNodesNum ++;
            }
            
            if( node->right != NULL ){
                nodeQueue.push( node->right );
                nextLevelNodesNum ++;
            }
            
            // Done with one node, check if all nodes in current level are all done.
            // If all done, switch to next level.
            // If next level is None, then the whole while() loop will stop.
            nodeNum++;
            if( nodeNum >= curLevelNodesNum ){
                // Add values of current level to temp list
                levelValuesList.push_back( *curLevelValues );
                curLevelValues = NULL;
                
                // Switch to next level
                curLevelNodesNum = nextLevelNodesNum;
                nextLevelNodesNum = 0;
                nodeNum = 0;
            }
            
        }
        
        // Reverse travel of list, and add the values to treeTraversal.
        for (list<vector<int>>::reverse_iterator rit= levelValuesList.rbegin(); rit != levelValuesList.rend(); ++rit)
            treeTraversal.push_back( *rit );
        
        return treeTraversal;
        
    }
};