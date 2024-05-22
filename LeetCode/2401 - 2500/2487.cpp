// 2487. Remove Nodes From Linked List

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

// Solution 1 using stack
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* ptr = head;
        while(ptr){
            while(!stk.empty() && stk.top()->val < ptr->val) stk.pop();
            stk.push(ptr);
            ptr = ptr->next;
        }
        ListNode* nxt = NULL;
        while(!stk.empty()){
            stk.top()->next = nxt;
            nxt = stk.top();
            stk.pop();
        }
        return nxt;
    }
};

// Solution 2 using recursion
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head) return NULL;
        ListNode* nxt = removeNodes(head->next);
        head->next = nxt;
        if(nxt && nxt->val > head->val) return nxt;
        return head;
    }
};