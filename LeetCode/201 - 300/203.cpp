/** Name : Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return head;
        }
        ListNode* ptr = head;
        while(head != NULL && head->val == val){
            head = head->next;
        }
        while(ptr->next != NULL){
            if(ptr->next->val == val){
                ListNode* temp = ptr->next;
                ptr->next = ptr->next->next;
                delete temp;
            }
            else{
                ptr = ptr->next;
            }
        }
        return head;
    }
};