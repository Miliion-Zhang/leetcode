/** Convert Sorted List to Binary Search Tree

	Given a singly linked list where elements are sorted in ascending order, 
	convert it to a height balanced BST.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = getListSize( head );
        if( size < 1 )
            return NULL;
        
        return sortedListToBST( head, 0, size-1 );
        //return NULL;
        
    }
    
    TreeNode* sortedListToBST(ListNode *& list, int start, int end) {
      if (start > end) return NULL;
	  // same as (start+end)/2, avoids overflow
	  int mid = start + (end - start) / 2;
	  TreeNode *leftChild = sortedListToBST(list, start, mid-1);
	  TreeNode *parent = new TreeNode(list->val);
	  parent->left = leftChild;
	  list = list->next;
	  parent->right = sortedListToBST(list, mid+1, end);
	  return parent;
	}
    
    int getListSize( ListNode *head ){
        if( head == NULL )
            return 0;
        
        int size = 1;
        while( head->next != NULL ){
            size++;
            head = head->next;
        }
        return size;
    }
};
