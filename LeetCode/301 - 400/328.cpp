// 328. Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* odd = head;
        ListNode* even = head->next;
        
        ListNode* evenhead = even;
        while(true){
            if(!odd || !even || !(even->next)){
                odd->next = evenhead;
                break;
            }
            odd->next = even->next;
            odd = even->next;
            if(odd->next == NULL){
                even->next = NULL;
                odd->next = evenhead;
                break;
            }
            even->next = odd->next;
            even = odd->next;            
        }
        return head;
    }
};