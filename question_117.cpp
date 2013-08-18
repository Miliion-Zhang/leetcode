/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
struct NodeLevel {
    TreeLinkNode *node;
    int level;
    NodeLevel(TreeLinkNode *node, int level) : node(node), level(level) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        // Empty tree or only have one level, need none processing
        if( root == NULL )
            return;
        if( root->left == NULL && root->right == NULL )
            return;
        
        int lastLevel = 1;
        TreeLinkNode *lastNode = NULL;
        TreeLinkNode *curNode = NULL;
        
        queue<NodeLevel *> nodeQueue;
        if( root->left )
            nodeQueue.push( new NodeLevel(root->left, lastLevel + 1) );
        if( root->right )
            nodeQueue.push( new NodeLevel(root->right, lastLevel + 1) );
        
        while( !nodeQueue.empty() ){
            
            NodeLevel *nodeLevel = nodeQueue.front();
            nodeQueue.pop();
            if( nodeLevel->level != lastLevel ){
                lastLevel = nodeLevel->level;
                lastNode = nodeLevel->node;
                if( lastNode->left )
                    nodeQueue.push( new NodeLevel(lastNode->left, lastLevel + 1) );
                if( lastNode->right )
                    nodeQueue.push( new NodeLevel(lastNode->right, lastLevel + 1) );
                delete nodeLevel;
                continue;
            }
            
            curNode = nodeLevel->node;
            delete nodeLevel;
            if( curNode->left )
                nodeQueue.push( new NodeLevel(curNode->left, lastLevel + 1) );
            if( curNode->right )
                nodeQueue.push( new NodeLevel(curNode->right, lastLevel + 1) );
            
            lastNode->next = curNode;
            lastNode = curNode;            
            
        }
    }
};