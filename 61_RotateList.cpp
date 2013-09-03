/** Rotate List

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    /**
     * Will take O(n) time and O(1) space.
     * Note: If k is bigger than length of the list, then think the list as
     *       a circle list, which means k should minus len and try again.
     */
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *lastNode = NULL;
        
        int len = getLength(head, lastNode);
        if( k > len && len > 0)
            k %= len;
        
        int lenLeft = len - k;
        if( lenLeft <= 0 || k == 0)
            return head;
        
        ListNode* cur = head;
        while( lenLeft > 1 ){// find the node before the new head
            cur = cur->next;
            lenLeft--;
        }
        
        ListNode *newHead = cur->next;
        cur->next = NULL;
        lastNode->next = head;
        
        return newHead;
        
    }
    
    int getLength(ListNode *head, ListNode* &lastNode){
        if( !head )
            return 0;
        
        int len = 0;
        lastNode = head;
        ListNode *cur = head;
        while( cur ){
            lastNode = cur;
            cur = cur->next;
            len++;
        }
        
        return len;
    }
};
