// 725. Split Linked List in Parts

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


// Solution 1 by counting the number of nodes in the linked list and then dividing it into k parts
// Time complexity: O(n+k)
// Space complexity: O(k) for the result vector
// Note: The solution is not optimal as it traverses the linked list twice and also creates a new node for each node in the linked list
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = 0;
        ListNode* ptr = head;
        while(ptr){
            ptr = ptr->next;
            count++;
        }
        vector<ListNode*> res(k, NULL);
        if(!head) return res;
        if(count <= k){
            ptr = head;
            int i = 0;
            while(ptr){
                res[i++] = new ListNode(ptr->val);
                ptr = ptr->next;
            }
        }
        else{
            int temp = count%k, i = 0;
            ptr = head;
            while(ptr){
                int cnt = count/k + (temp > 0);
                ListNode* node = new ListNode(ptr->val), *p = node;
                cnt--;
                ptr = ptr->next;
                while(cnt > 0){
                    p->next = new ListNode(ptr->val);
                    ptr = ptr->next;
                    p = p->next;
                    cnt--;
                }
                temp--;
                res[i++] = node;
            }
        }
        return res;
    }
};

// Solution 1 but simplified
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k);
        if(!head) return result;
        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }
        int width = n / k;
        int rem = n % k;
        curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* root = new ListNode(0);
            ListNode* write = root;
            for (int j = 0; j < width + (i < rem ? 1 : 0); j++) {
                write->next = new ListNode(curr->val);
                write = write->next;
                if (curr) curr = curr->next;
            }
            result[i] = (root->next);
        }
        return result;
    }
};


// Solution 2 by splitting the linked list into k parts by modifying the linked list
// Time complexity: O(n + k)
// Space complexity: O(k)

// no need to create a new node for each node in the linked list instead, we can modify the linked list by adding NULL to the end of each part
// and then split the linked list into k parts

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k);
        if(!head) return res;
        int count = 0;
        ListNode* ptr = head;
        while(ptr){
            ptr = ptr->next;
            count++;
        }
        int width = count/k, rem = count%k;
        ptr = head;
        for(int i = 0; i < k; i++){
            ListNode* node = ptr;
            for(int j = 0; j < width + (i < rem ? 1 : 0)-1; j++)
                if(ptr) ptr = ptr->next;
            if(ptr){
                ListNode* prev = ptr;
                ptr = ptr->next;
                prev->next = NULL;
            }
            res[i] = node;
        }
        return res;
    }
};