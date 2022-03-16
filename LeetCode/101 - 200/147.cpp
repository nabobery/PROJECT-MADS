// 147. Insertion Sort List
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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp = new ListNode();
        ListNode* ptr = head;
        while(ptr != NULL){
            ListNode* prev = temp;
            while(prev->next != NULL && prev->next->val < ptr->val){
                prev = prev->next;
            }
            ListNode* next = ptr->next;
            ptr->next = prev->next;
            prev->next = ptr;
            ptr = next;
        }
        return temp->next;
    }
};
