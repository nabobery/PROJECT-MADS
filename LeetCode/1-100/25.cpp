// 25. Reverse Nodes in k-Group
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
 // My naive solution using vector O(n) time and Space
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> arr;
        ListNode* ptr = head;
        while(ptr != NULL){
            arr.push_back(ptr->val);
            ptr = ptr->next;
        }
        int size = arr.size();
        int n = size/k;
        for(int i = 0; i < n;i++){
            reverse(arr.begin() + i*k, arr.begin() + (i+1)*k);
        }
        ptr = head;
        for(int i = 0; i < size;i++){
            ptr->val = arr[i];
            ptr = ptr->next;
        }
        return head;
    }
};

// recursive solution using O(n) space (because of stack)
// basic idea that we reverse first k elements and then recurse till the end
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        // to check if number of nodes < k so return and no changes need to be done
        for(int i = 0; i < k; i++){
            if(ptr == nullptr) return head;
            ptr = ptr->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        for(int i = 0; i < k; i++){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};

// iterative solution using O(1) space
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(!head||k==1) return head;
        auto dummy = ListNode(-1);
        preheader.next = head;
        auto len=0;
        for(auto curr = &preheader;cur = curr->next ;len++) ;
        for(auto prev = &preheader;k<=len; len-=k) {
            auto curr = prev->next;
            auto nex = curr->next;
            for(int i=1;i<k;++i) {
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=curr->next;
            }
            prev = curr;

        }
        return dummy.next;
    }
};
