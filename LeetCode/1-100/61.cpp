// 61. Rotate List
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
 // my naive slow solution using O(n) space
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(), start = 0;
        for (; k %= n; n -= k, start += k) {
            for (int i = 0; i < k; i++) {
                swap(nums[start + i], nums[start + n - k + i]);
            }
        }
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0) return head;
        ListNode* ptr = head;
        vector<int> temp;
        while(ptr){
            temp.push_back(ptr->val);
            ptr = ptr->next;
        }
        if(temp.size() % k == 0 && k >= temp.size()) return head;
        rotate(temp,k);
        ptr = head;
        for(int n : temp){
            ptr->val = n;
            ptr = ptr->next;
        }
        return head;
    }
};

// O(n) time  and O(1) space solution
// Example 1->2->3->4->5-> NULL => 1->2->3->4->5->1 (in a circular way linked) => 4->5->1->2->3->NULL
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // if k = 0 or if there's 0 0r 1 nodes return head
        if(!head || !head->next || k == 0) return head;
        // which stores number of nodes
        int count = 1;
        ListNode* ptr = head;
        // traverse till tail
        while(ptr->next){
            ptr = ptr->next;
            count++;
        }
        ptr->next = head; // set tail->next as head
        // k = n - n%k which is number of nodes which are ot rotated right
        k = count - (k % count);
        // we traverse and find the node where the node should be connected to NULL
        while(k-- > 0)
            ptr = ptr->next;
        head = ptr->next;
        ptr->next = NULL;
        return head;
    }
};

