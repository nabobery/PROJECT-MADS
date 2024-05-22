// 2816. Double a Number Represented as a Linked List

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

// Solution 1 by double reversal of linked list (Better approach)
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* prev = NULL, *curr = head;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        curr = prev; prev = NULL;
        int carry = 0;
        while(curr){
            ListNode* nxt = curr->next;
            int temp = curr->val*2 + carry;
            carry = temp/10;
            curr-> val = temp%10;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        if(carry == 0) return prev;
        ListNode* h = new ListNode(1);
        h-> next = prev;
        return h;
    }
};

// Solution 2 by using stack
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        stack<int> s;
        ListNode* curr = head;
        while(curr){
            s.push(curr->val);
            curr = curr->next;
        }
        int carry = 0;
        ListNode* prev = NULL;
        while(!s.empty()){
            int temp = s.top()*2 + carry;
            carry = temp/10;
            ListNode* node = new ListNode(temp%10);
            node->next = prev;
            prev = node;
            s.pop();
        }
        if(carry == 0) return prev;
        ListNode* h = new ListNode(1);
        h->next = prev;
        return h;
    }
};