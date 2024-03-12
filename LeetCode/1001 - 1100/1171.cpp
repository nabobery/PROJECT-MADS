// 1171. Remove Zero Sum Consecutive Nodes from Linked List

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

// Simple and Naive Solution using prefix sum, hashmap and set
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> arr;
        ListNode* ptr = head;
        while(ptr){
            arr.push_back(ptr->val);
            ptr = ptr->next;
        }
        int n = arr.size(), sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        set<int> s;
        for(int i = 0; i < n;i++) s.insert(i);
        for(int i = 0; i < n;i++){
            sum += arr[i];
            if(!mp.count(sum)) mp[sum] = i;
            else{
                if(s.count(mp[sum]+1)){
                    for(int j = mp[sum]+1; j <= i;j++)
                        s.erase(j);
                }
                mp[sum] = i;
            }
        }
        if(s.empty()) return NULL;
        ptr = NULL;
        for(auto i : s){
            if(ptr) ptr = ptr->next;
            else ptr = head;
            ptr->val = arr[i];
        }
        ptr->next = NULL;
        return head;
    }
};

// Solution 2 Optimised Solution using prefix sum and hashmap without converting linked list to array
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*> mp;
        int sum = 0;
        for(ListNode* i = dummy; i; i = i->next){
            sum += i->val;
            mp[sum] = i;
        }
        sum = 0;
        for(ListNode* i = dummy; i; i = i->next){
            sum += i->val;
            i->next = mp[sum]->next;
        }
        return dummy->next;
    }
};