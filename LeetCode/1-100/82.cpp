// 82. Remove Duplicates from Sorted List II
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 // Two pointers O(n) time and O(1) space solution
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // if there's only zero or one node
        if(head == NULL || head->next == NULL) return head;
        // use dead node(sentinel) for avoiding edge cases
        ListNode* dummy = new ListNode(0,head); // linking dummy->next to head
        ListNode* prev = dummy; // storing dummy as prev
        while(head != NULL){
            // skip duplicates
            if(head->next != NULL && head->val == head->next->val){
                while(head->next != NULL && head->val == head->next->val){
                    head = head->next;
                }
                // link prev to the next node
                prev->next = head->next;
            }
            // else just move prev forward
            else{
                prev = prev->next;
            }
            // move head forward
            head = head->next;
        }
        return (dummy->next);
    }
};

