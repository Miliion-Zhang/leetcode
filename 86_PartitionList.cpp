/** Partition List

    Given a linked list and a value x, partition it such that all nodes less than x 
    come before nodes greater than or equal to x.

    You should preserve the original relative order of the nodes in each of the
    two partitions.

    For example,
    Given 1->4->3->2->5->2 and x = 3,
    return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x) {
        if( head == NULL )
            return NULL;
        
        ListNode *smallerHead = NULL;
        ListNode *smallerP = NULL;
        ListNode *biggerHead = NULL;
        ListNode *biggerP = NULL;
        ListNode *cur = head;
        
        while( cur ){
            if( cur->val < x ){ // should insert to smaller lsit
                if( smallerHead == NULL )
                    smallerHead = cur;
                if( smallerP )
                    smallerP->next = cur;
                smallerP = cur;
            }
            else {  // should insert to bigger list
                if( biggerHead == NULL )
                    biggerHead = cur;
                if( biggerP )
                    biggerP->next = cur;
                biggerP = cur;
            }
            cur = cur->next;
        }
        
        // Determine head node and link small / bigger list together if can
        if( smallerHead ){
            head = smallerHead;
            smallerP->next = biggerHead;
        }
        else
            head = biggerHead;
        
        if( biggerP )   // Clear the last node's next
            biggerP->next = NULL;
        
        return head;
        
    }
};