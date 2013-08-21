/** Merge k Sorted Lists
 * 
 * Merge k sorted linked lists and return it as one sorted list. 
 * Analyze and describe its complexity.
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
    /**
     * Current version, getMinNode() should cost time O(k), so the time all is
     * O(nk) which n is the number of all nodes.
     * 
     * But if we optimize getMinNode() by maintaining a min-heap, the time cost
     * in all can reduce to O(n*logk) but the space is O(k).
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int size = lists.size();
        if( size < 1 )
            return NULL;
        
        ListNode *head = getMinNode( lists );
        ListNode *cur = head;
        while( cur ){
            cur->next = getMinNode( lists );
            cur = cur->next;
        }
        
        return head;
    }
    
    /**
     * Get the smallest node in K lists.
     * Current version is searching lists linearly and the time is O(k).
     * 
     * But we can speed it up by maintaining a min-heap, the items in min-heap
     * is (index,val), each time get a min one and push into a new one. So the
     * time cost can reduce to O(logk) but the space cost is O(k).
     */
    ListNode *getMinNode(vector<ListNode *> &lists) {
        int minIndex = 0;
        int size = lists.size();
        ListNode* minNode = lists[0];
        for( int i = 1; i < size ; i++ ) {
            ListNode *cur = lists[i];
            if( cur == NULL )
                continue;
            
            if( minNode == NULL || cur->val < minNode->val ){
                minIndex = i;
                minNode = cur;
            }
        }
        
        if( minNode != NULL )
            lists[minIndex] = minNode->next;
        
        return minNode;
    }
};
