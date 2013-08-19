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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if( !l1 && !l2 )
            return NULL;
        
        if( !l1 && l2 )
            return l2;
        
        if( l1 && !l2 )
            return l1;
        
        ListNode *returned = NULL;
        if( l1->val < l2->val ){
            returned = l1;
            l1 = l1->next;
        }
        else {
            returned = l2;
            l2 = l2->next;
        }
        
        ListNode *merged = returned;
        while(1){
            if( !l2 ){
                merged->next = l1;
                break;
            }
            
            if( !l1 ){
                merged->next = l2;
                break;
            }
            
            if( l1->val < l2->val ){
                merged->next = l1;
                merged = merged->next;
                l1 = l1->next;
            }
            else {
                merged->next = l2;
                merged = merged->next;
                l2 = l2->next;
            }
        }
        
        return returned;
    }
};