// 92. Reverse Linked List II

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

// Solution 1: In one pass but not efficient
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* prev = NULL, *curr = head, *start, *temp;
        int cnt = 1;
        while(curr){
            if(cnt == left) break;
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        start = prev;
        prev = curr;
        curr = curr->next;
        cnt++;
        while(curr && cnt <= right){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            cnt++;
        }
        if(left > 1){
            if(start->next) start->next->next = curr;
            if(start) start->next = prev;
        }
        else{
            head->next = curr;
            head = prev;
        }
        return head;
    }
};

// Solution 2: In one pass using dummy node and two pointers
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy, *curr;
        for(int i = 0; i < left-1;i++) prev = prev->next;
        curr = prev->next;
        for(int i = 0; i < right-left;i++){
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        return dummy->next;
    }
};