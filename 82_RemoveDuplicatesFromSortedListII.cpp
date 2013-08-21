/** Remove Duplicates from Sorted List II
 * 
 * Given a sorted linked list, delete all nodes that have duplicate numbers, 
 * leaving only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        head = getFirstUniqueNode( head );
        if( head == NULL )
            return head;
        
        ListNode *curNode = head;
        ListNode *nextNode = getFirstUniqueNode( curNode->next );
        while(true){
            curNode->next = nextNode;
            if( nextNode == NULL )
                break;
            
            // Move on to next node.
            curNode = nextNode;
            nextNode = getFirstUniqueNode( curNode->next );
        }
        
        return head;
        
    }
    
    /**
     * Delete all duplicate nodes until find the first unique one.
     * History:
     * V1.1  Change recursion function to non-recursion one.(But can't see the improvement from running result...)
     * V1.0  First edition, recursion version.
     */
    ListNode *getFirstUniqueNode(ListNode *head){
        while(true){
            if( head == NULL )
                return NULL;
            
            int firstVal = head->val;
            
            ListNode *nextNode = head->next;
            bool firstIsUnique = (nextNode == NULL) ? true : (firstVal != nextNode->val);
            if( firstIsUnique )
                return head;
            
            // Not unique, remover all duplicate nodes
            delete head;
            head = NULL;
            while( nextNode != NULL && firstVal == nextNode->val ){
                ListNode *delNode = nextNode;
                nextNode = nextNode->next;
                delete delNode;
            }
            
            // Make sure the nextNode is unique.
            // so change head to nextNode, and check again.
            head = nextNode;
            
        }
        
    }
};