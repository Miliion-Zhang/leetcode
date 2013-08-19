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
