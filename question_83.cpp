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
        int curValue = 0;
        ListNode *curNode = NULL;
        ListNode *nextNode = NULL;
        
        if( head == NULL )
            return head;
        
        curNode = head;
        while( curNode != NULL && curNode->next != NULL ){
            curValue = curNode->val;
            nextNode = curNode->next;
            // skip all nodes with the same value
            while( nextNode != NULL && curValue == nextNode->val ){
                ListNode *delNode = nextNode;
                nextNode = nextNode->next;
                delete delNode;
            }
            
            // Update curNode->next and move on to next node.
            curNode->next = nextNode;
            curNode = nextNode;
        }
        
        // all done
        return head;
        
    }
};