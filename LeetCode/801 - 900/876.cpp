// 876. Middle of the Linked List
// My naive solution (goos time wise but avg space wise)
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
    ListNode* middleNode(ListNode* head) {
        int count  = 0;
        ListNode* ptr = head;
        while(ptr){
            count++;
            ptr = ptr->next;   
        }
        count = count/2;
        ptr = head;
        int i = 0;
        while(i != count){
            ptr = ptr->next;
            i++;
        }
        return ptr;
    }
};

// Not great solution
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// same as my naive sol
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> A = {head};
        while (A.back()->next != NULL)
            A.push_back(A.back()->next);
        return A[A.size() / 2];
    }
};

