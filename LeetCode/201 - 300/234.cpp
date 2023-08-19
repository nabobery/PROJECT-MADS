// 234. Palindrome Linked List

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


// Solution 1: Using O(n) time and O(n) space
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        int n = arr.size();
        for(int i = 0; i < n/2;i++){
            if(arr[i] != arr[n-i-1]) return false;
        }
        return true;
    }
};

// Solution 2: Using O(n) time and O(1) space
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head, *prev, *temp;
        // trvaer the list until slow reaches the middle and fast reaches the end
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // save slow in prev and move slow forward and divide the the 2nd list by making the middle element's next point to null
        prev = slow;
        slow = slow->next;
        prev->next = NULL;
        // reverse the 2nd part of list
        while(slow){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        // fast is 1st part which traverses normally and slow traverses in reverse and starts from the end
        fast = head, slow = prev;
        // check if the list is a palindrome
        while(slow){
            if(fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};