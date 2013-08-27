/**

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the
values in the list, only nodes itself can be changed.

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
    ListNode *swapPairs(ListNode *head) {
        if( head == NULL || head->next == NULL ) // NULL or only one node
            return head;
        
        ListNode *lastGroup = NULL;  // Last node in last swapped group
        ListNode *last = head;             // last node
        ListNode *cur = head->next;   // current node
        head = cur;              //As the return value
        bool swap = true;    // State, false to move to next one, true to swap
        while( cur ){
            if( swap ){
                // Swap current node and last node
                ListNode *next = cur->next;
                cur->next = last;
                last->next = next;
                if( lastGroup ){
                    lastGroup->next = cur;
                }
                lastGroup = last;

                // Move to next one
                last = last;
                cur = next;
            }
            else{
                // Just move to next one
                ListNode *next = cur->next;
                last = cur;
                cur = next;
            }
            
            // Change state
            swap = !swap;
        }
        
        return head;
    }
};
