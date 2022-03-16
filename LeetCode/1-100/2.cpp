// 2. Add Two Numbers
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
 // my naive solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ptr1 = l1, *ptr2 = l2;
        while(ptr1 != NULL && ptr2 != NULL){
            int temp = ptr1->val + ptr2->val + carry;
            ptr1->val = (temp % 10);
            carry = temp/10;
            if(!ptr1->next || !ptr2->next) break;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if(!ptr1->next && ptr2->next){
            ptr1->next = ptr2->next;
            ptr2 = ptr2->next;
            while(ptr2){
                int temp = ptr2->val + carry;
                ptr2->val = temp % 10;
                carry = temp/10;
                if(!ptr2->next) break;
                ptr2 = ptr2->next;
            }
            if(carry != 0){
                ptr2->next = new ListNode(1);
            }
        }
        else if(!ptr2->next && ptr1->next){
            ptr1 = ptr1->next;
            while(ptr1){
                int temp = ptr1->val + carry;
                ptr1->val = temp % 10;
                carry = temp/10;
                if(!ptr1->next) break;
                ptr1 = ptr1->next;
            }
            if(carry != 0){
                ptr1->next = new ListNode(1);
            }
        }
        else{
            if(carry != 0){
                ptr1->next = new ListNode(1);
            }
        }
        return l1;
    }
};

// creation of nodes instead of using l1 and l2 nodes using dummy head
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* ptr1 = l1, *ptr2 = l2, *ptr = head;
        while(ptr1 != NULL || ptr2 != NULL){
            int x = (ptr1 != NULL) ? ptr1->val : 0;
            int y = (ptr2 != NULL) ? ptr2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            ptr->next = new ListNode(sum % 10);
            ptr = ptr->next;
            if (ptr1 != NULL) ptr1 = ptr1->next;
            if (ptr2 != NULL) ptr2 = ptr2->next;
        }
        if (carry > 0) {
            ptr->next = new ListNode(carry);
        }
        return head->next;
    }
};

