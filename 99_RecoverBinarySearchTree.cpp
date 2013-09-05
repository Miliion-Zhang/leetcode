/** Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise
a constant space solution?

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
    TreeNode *firstMistake;
    TreeNode *secondMistake;
    
public:
    /**
     * Will takes O(1) space and O(n) time.
     * Inorder tavel a binary search tree will get a array in increasing order, so
     * we can simply find the first position and second postion that meats 
     * following condition:
     * A[i] > A[i+1], so these are swapped nodes, then swap them back.
     * But it will cost O(n) space.
     *
     * Notice that we only care about the nodes that do not meet the increasing
     * order, so we can only keep two pointer of current node and last node, 
     * and the breaking point will be detected.
     */
    void recoverTree(TreeNode *root) {
        
        firstMistake = NULL;
        secondMistake = NULL;
        
        stack<TreeNode *> nodeStack; // Store the step of inorder travel
        TreeNode *cur = root;
        TreeNode *last = NULL;

         // make sure the node will not be pushed to stack again and again
        bool isPushed = false; 
        while(1){
            if( !cur ){
                if( nodeStack.empty() )
                    break;
                
                cur = nodeStack.top();
                nodeStack.pop();
                isPushed = true;
            }
            
            if( isPushed ){// current node is pop out from stack
                if( last && cur->val < last->val ){ // got mistake
                    if( !firstMistake ){ 
                         // Must update first and second mistake nodes both, 
                         // because if only have two elements in tree, e.g., 
                         // [0,1], then will only find the first mistake and will
                         // never find the sencond mistake.
                        firstMistake = last;
                        secondMistake = cur;
                    }
                    else{
                        secondMistake = cur;
                        // a little optimisze, we don't need to travel tree if already
                        // found the second mistake.
                        break;  
                    }
                }
                
                // visit current
                // visit right sub-tree
                last = cur;
                cur = cur->right;
                isPushed = false;
            }
            else{
                nodeStack.push(cur);
                cur = cur->left;    //visit left sub-tree first
            }
        }
        
        //swap two mistake nodes' value
        int val = firstMistake->val;
        firstMistake->val = secondMistake->val;
        secondMistake->val = val;       
    }
};
