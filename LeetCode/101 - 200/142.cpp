// 142. Linked List Cycle II
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// my naive solution using map
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        map<ListNode*,int> mp;
        while(head != NULL){
            if(mp.find(head) == mp.end()){
                mp[head] = 1;
            }
            else{
                return head;
            }
            head = head->next;
        }
        return NULL;
    }
};

// using slow and fast pointers O(n) time and O(1) space
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!(fast && fast->next)) return NULL;
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};

// one more implementation of slow and fast pointers
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
                while (head != slow) {
                    head = head->next;
                    slow = slow->next;
                }
                return head;
            }
        }
        return NULL;
    }
};
