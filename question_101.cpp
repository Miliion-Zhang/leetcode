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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if( root == NULL )
            return true;
        
        // Change Solution version, recursively or iteratively.
        //return isSymmetricRecursively(root->left, root->right);
        return isSymmetricIteratively(root);
        
    }
    
    /**
     * Iterative version, root must not be NULL.
     */
    bool isSymmetricIteratively(TreeNode *root){
        vector<TreeNode *> *curLevel = new vector<TreeNode *>();
        vector<TreeNode *> *nextLevel = new vector<TreeNode *>();

        // Push root's children as current level
        if( root->left != NULL )
            curLevel->push_back( root->left );
        
        if( root->right != NULL )
            curLevel->push_back( root->right );
        
        while( curLevel->size() > 0 ){
            int curLevelSize = curLevel->size();
            
            // If nodes number in current level is not even, then not symmetric.
            if( curLevelSize % 2 != 0 )
                return false;
            
            // For each nodes in current level, check their symmetric and add their
            // children nodes to nexLevel.
            for( int i=0; i < curLevelSize ; i++ ){
                int middle = curLevelSize / 2;
                
                // Check symmetric
                if( i < middle ){
                    TreeNode *leftNode = (*curLevel)[i];
                    TreeNode *rightNode = (*curLevel)[ curLevelSize - 1 - i ];
                    
                    // Symmetric nodes are NULL, continue to check next.
                    if( leftNode == NULL && rightNode == NULL )
                        continue;
                    
                    // Not symmetric, return false directly.
                    if( (leftNode == NULL && rightNode != NULL)
                        || (leftNode != NULL && rightNode == NULL)
                        || (leftNode->val != rightNode->val) )
                        return false;
                }
                
                // Add each node's children(can be NULL) to nextLevel
                TreeNode *cur = (*curLevel)[i];
                if( cur != NULL ){
                    nextLevel->push_back( cur->left );
                    nextLevel->push_back( cur->right );
                }
            }
            
            // Swith to nextLevle
            vector<TreeNode *> *temp = curLevel;
            curLevel = nextLevel;
            nextLevel = temp;
            nextLevel->clear(); // Must clear the values in it before using it next time.
        }
        
        // All checking pass, is symmectric
        return true;        
    }
    
    
    /**
     * Recursive version
     */
    bool isSymmetricRecursively(TreeNode *left, TreeNode *right){
        if( left == NULL && right == NULL )
            return true;
        
        if( (left == NULL && right != NULL)
            || (left != NULL && right == NULL) )
            return false;
        
        if( left->val != right->val )
            return false;
        else
            return isSymmetricRecursively(left->left, right->right)
                && isSymmetricRecursively(left->right, right->left);
    }    
    
    
};