// 24. Swap Nodes in Pairs
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
 // using recursion
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // base case when we reach the end
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* recur = swapPairs(head->next->next);
        first->next = recur;
        second->next = first;
        return second;
    }
};

