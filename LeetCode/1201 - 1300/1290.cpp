//1290. Convert Binary Number in a Linked List to Integer
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

// Not memory efficient solution but time efficient
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* ptr = head;
        vector<int> bin;
        while(ptr != NULL){
            bin.push_back(ptr->val);
            ptr = ptr->next;
        }
        int base = 1, result = 0;
        for(int i = bin.size() - 1; i >= 0; i--){
            if(bin[i] == 1){
                result += base;
            }
            base *= 2;
        }
        return result;
    }
};
// Memory efficient
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result  = head->val;
        while(head->next != NULL){
            result = result*2 + head->next->val;
            head = head->next;
        }
        return result;
    }
};
// kind efficient
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result  = 0;
        while(head != NULL){
            result = (result << 1) | head->val;
            head = head->next;
        }
        return result;
    }
};
