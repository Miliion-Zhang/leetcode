/** Populating Next Right Pointers in Each Node

	Given a binary tree

		struct TreeLinkNode {
		  TreeLinkNode *left;
		  TreeLinkNode *right;
		  TreeLinkNode *next;
		}
	Populate each next pointer to point to its next right node. If there is no
	next right node, the next pointer should be set to NULL.

	Initially, all next pointers are set to NULL.

	Note:

	You may only use constant extra space.
	You may assume that it is a perfect binary tree (ie, all leaves are at the
	same level, and every parent has two children).
	For example,
	Given the following perfect binary tree,

			 1
		   /  \
		  2    3
		 / \  / \
		4  5  6  7
	After calling your function, the tree should look like:

			 1 -> NULL
		   /  \
		  2 -> 3 -> NULL
		 / \  / \
		4->5->6->7 -> NULL

*/


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
