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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if( head == NULL || m >=n )
            return head;
        
        // Notice !!! 
        // The m, n satisfy the following condition:
        //  1 <= m < n <= length of list,
        // and m, n is indexed from 1.
        ListNode *begin = NULL;
        ListNode *beforeBegin = NULL;
        ListNode *last = NULL;
        ListNode *cur = head;
        int cnt = 1;
        
        while( cnt <= n ){
            if( cnt == m-1 ) // Remember the previous node of reverted area.
                beforeBegin = cur;
            
            if( cnt == m ){  // Remember the begining node of reverted area.
                begin = cur;
            }
            
            if( cnt > m ){  // Revert list
                ListNode *next = cur->next;
                cur->next = last;
                last = cur;
                cur = next;
            }
            else {          // normal area, just move to next one
                last = cur;
                cur = cur->next;
            }
            
            cnt++;
        }
        
        if( beforeBegin )   // only need update it if m > 1
            beforeBegin->next = last;
        begin->next = cur;
        
        if( begin == head ) // m=1, so the reverted list should be the new head
            return last;
        else
            return head;
    }
};