// 19. Remove Nth Node From End of List

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


// Solution 1 with 2 passes
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num = 0, p = 0;
        ListNode* ptr = head;
        while(ptr){
            ptr = ptr->next;
            num++;
        }
        num -= n;
        if(num == 0){
            if(!head->next) return NULL;
            ListNode* temp = head->next;
            head->val = temp->val;
            head->next = temp->next;
            delete temp;
            return head;
        }
        ptr = head;
        ListNode* prev = NULL;
        while(ptr){
            if(p == num){
                ListNode* temp = ptr->next;
                prev->next = temp;
                delete ptr;
                break;
            }
            prev = ptr;
            ptr = ptr->next;
            p++;
        }
        return head;
    }
};

// Solution 2 with 1 pass
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = head;
        // move fast pointer n steps ahead
        for(int i = 0; i < n;i++) fast = fast->next;
        // if end reached,it means we have to remove first node
        if(!fast) return head->next;
        // move slow poointer while moving the fast point so that they differ by n steps
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        // make the previous node of the node to be deleted next pointer pointed to node to be deleted next pointer
        slow->next = slow->next->next;
        return head;
        
    }
};