/** Reverse Nodes in k-Group
 * 
 * Given a linked list, reverse the nodes of a linked list k at a time 
 * and return its modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in
 * the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 * Only constant memory is allowed.

 * For example,
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 *
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if( head == NULL || k < 2 ) // not valid group
            return head;
        
        bool foundNewHead = false;
        ListNode *first = head;
        ListNode *cur = first->next;
        ListNode *lastGroup = NULL;
        int cnt = 1;
        while( cur != NULL ){
            ListNode *nextGroup = cur->next;
            cnt++;
            if( cnt >= k ){
                if( !foundNewHead ){
                    head = cur;
                    foundNewHead = true;
                }
                
                reverseList( first, cur );
                first->next = nextGroup;
                if( lastGroup )
                    lastGroup->next = cur;
                
                lastGroup = first;
                
                if( !nextGroup )
                    break;
                first = nextGroup;
                cur = first->next;
                cnt = 1;
                
            }
            else {
                cur = cur->next;
            }
        }
        
        return head;        
    }
    
    /**
     * Reverse the lostNode given the from pointer and to pointer,
     * notice that the from pointer must be ancestor of to pointer,
     * and finally from->next will point to NULL.
     */
    void reverseList(ListNode *from, ListNode *to){
        ListNode *cur = from;
        ListNode *last = NULL;
        while( cur != to ){
            ListNode *next = cur->next;
            cur->next = last;
            last = cur;
            cur = next;
        }
        to->next = last;
        from->next = NULL;
    }
};
