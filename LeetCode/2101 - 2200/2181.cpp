// 2181. Merge Nodes in Between Zeros

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

// Solution 1 using 2 pointers
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* res = NULL, *ptr = head, *temp;
        int sum = 0;
        ptr = ptr->next;
        while(ptr){
            if(ptr->val) sum += ptr->val;
            else{
                if(res){
                    ListNode* t = new ListNode(sum);
                    temp->next = t;
                    temp = temp->next;
                }
                else{
                    res = new ListNode(sum);
                    temp = res;
                }
                sum = 0;
            }
            ptr = ptr->next;
        }
        return res;
    }
};

// Solution 2 using 2 pointers by modifying the input list
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ptr = head, *temp = head;
        int sum = 0;
        ptr = ptr->next;
        while(ptr){
            if(ptr->val) sum += ptr->val;
            else{
                if(sum){
                    temp->val = sum;
                    if(ptr->next){
                        temp->next = ptr;
                        temp = ptr;
                    }
                }
                sum = 0;
            }
            ptr = ptr->next;
        }
        temp->next = NULL;
        return head;
    }
};