/** Add Two Numbers
 * 
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain 
 * a single digit. Add the two numbers and return it as a linked list.
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if( !l1 && !l2 )
            return NULL;
        
        ListNode *head = NULL;
        ListNode *last = NULL;
        
        int carry = 0;
        int val1 = 0;
        int val2 = 0;
        while( l1 || l2 || carry > 0 ){
            val1 = l1 ? l1->val : 0;
            val2 = l2 ? l2->val : 0;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
            
            int sum = val1 + val2 + carry;
            if( sum > 9 ){
                carry = 1;
                sum -= 10;
            }
            else {
                carry = 0;
            }
            
            ListNode *sumNode = new ListNode( sum );
            if( !head )
                head = sumNode;
            
            if( last )
                last->next = sumNode;
            
            last = sumNode;
        }
        
        return head;
    }
};
