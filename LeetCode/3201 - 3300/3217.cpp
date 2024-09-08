// 3217. Delete Nodes From Linked List Present in Array

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

// Solution 1 using dummy node and delete node helper function
// Time complexity: O(n)
// Space complexity: O(k)
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode* ptr = head, *dummy = new ListNode(0, head), *prev = dummy;
        while(ptr){
            if(s.count(ptr->val)){
                if(ptr->next) deleteNode(ptr);
                else{
                    prev->next = NULL;
                    delete ptr;
                    break;
                }
            }
            else prev = ptr;
            ptr = prev->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

// Solution 2 using dummy node and without delete node helper function
// Time complexity: O(n)
// Space complexity: O(k)
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(0, head), *ptr = dummy;
        while(ptr->next){
            if(s.count(ptr->next->val))
                ptr->next = ptr->next->next;
            else ptr = ptr->next;
        }
        return dummy->next;
    }
};