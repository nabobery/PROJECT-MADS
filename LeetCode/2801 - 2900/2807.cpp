// 2807. Insert Greatest Common Divisors in Linked List

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

// Soluiton 1 by inserting GCD of adjacent nodes in the linked list
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ptr = head;
        while(ptr && ptr->next){
            int g = gcd(ptr->val, ptr->next->val);
            ListNode* node = new ListNode(g), *temp = ptr->next;
            ptr->next = node;
            node->next = temp;
            ptr = node->next;
        }
        return head;
    }
};