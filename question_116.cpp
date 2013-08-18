/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if( root == NULL )
            return ;
        
		// Only one level, no need to process
        if( root->left == NULL )
            return ;
        
        // Start to travel the tree level by level from level 2.
		// Initialize all data we need, and put nessary nodes to queue.
        unsigned int curLevelSize = 2;
        int index = 1;
        TreeLinkNode *lastNode = root->left;
        TreeLinkNode *curNode = NULL;
        queue<TreeLinkNode *> nodeQueue;
        nodeQueue.push( root->right );
        if( root->left->left ){	 // because one node has two children or None
            nodeQueue.push( root->left->left );
            nodeQueue.push( root->left->right );
        }
        while( !nodeQueue.empty() ){
            // Done with one level, switch to next level
			if( index >= curLevelSize ){
                curLevelSize = curLevelSize << 1;
                lastNode = nodeQueue.front();
                nodeQueue.pop();
                if( lastNode->left ){	// because one node has two children or None
                    nodeQueue.push( lastNode->left );
					nodeQueue.push( lastNode->right );
				}                    
                index = 1;
                continue;
            }
            
			// Visit a node, and put its children to queue for visiting in future.
            curNode = nodeQueue.front();
            nodeQueue.pop();
            if(curNode->left){	 // because one node has two children or None
                nodeQueue.push(curNode->left);
				nodeQueue.push(curNode->right);
			}                
            
			// Do connect the node under same level, and continue to deal with next node
            lastNode->next = curNode;
            lastNode = curNode;
            index += 1; 
            
        }
    }
};