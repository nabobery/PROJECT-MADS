// 141. Linked List Cycle
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// my naive solution using set O(N) time and space solution
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        unordered_set<ListNode*> s;
        while(head){
            if(s.count(head)) return true;
            else s.insert(head);
            head = head->next;
        }
        return false;
    }
};

// my naive O(N) time and O(1) space solution using 2 pointers
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode *ptr1 = head, *ptr2 = head;
        while(ptr2 && ptr2->next){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            if(ptr1 == ptr2){
                return true;
            }
        }
        return false;
    }
};

