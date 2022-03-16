// 143. Reorder List
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

// Recursion bruteforce (slow but memory efficient)
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;
        ListNode* second_last = head;
        while(second_last->next->next)
            second_last = second_last->next;
        second_last->next->next = head->next;
        head->next = second_last->next;
        second_last->next = NULL;
        reorderList(head->next->next);
    }
};

// using stack but fast
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;
        stack<ListNode*> stk;
        ListNode *ptr = head;
        int size = 0;
        while(ptr != NULL){
            stk.push(ptr);
            size++;
            ptr = ptr->next;
        }
        ListNode * temp = head;
        for(int i = 0; i < size/2;i++){
            ListNode* element = stk.top();
            stk.pop();
            element->next = temp->next;
            temp->next = element;
            temp = temp->next->next;
        }
        temp->next = NULL;
    }
};

// using 2 pointers 
// efficient both ways(memory and time)
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head->next)
            return;
        ListNode* slow = head;
        ListNode* fast = head;
        // finding mid
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        ListNode* ptr1 = mid;
        ListNode* ptr2 = mid->next;
        ListNode *pptr1= NULL, *pptr2 = NULL;
        mid->next = NULL;
        // reversing the second list
        while(ptr2){
            pptr1 = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr2->next;
            ptr1->next = pptr1;
        }
        mid = ptr1;
        ptr1 = head;
        ptr2 = mid;
        // merging both of them
        while(ptr2){
            pptr1 = ptr1;
            pptr2 = ptr2;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            pptr1->next = pptr2;
            pptr2->next = ptr1;
        }
    }
};
