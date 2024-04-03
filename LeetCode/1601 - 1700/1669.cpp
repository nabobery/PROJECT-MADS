// 1669. Merge In Between Linked Lists
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

// Solution 1 Naive and Simple, FInding prev_a and next_b and then merging with list2
// Time complexity: O(n+m)
// Space complexity: O(1)
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ptr = list1, *prev_a, *next_b = NULL;
        int i = 0;
        while(ptr){
            if(i == a-1) prev_a = ptr;
            if(i == b+1){
                next_b = ptr;
                break;
            }
            i++;
            ptr = ptr->next;
        }
        prev_a->next = list2;
        ptr = list2;
        while(ptr->next) ptr = ptr->next;
        ptr->next = next_b;
        return list1;
    }
};

// Solution 2 Using a vector to store the nodes and then merging with list2
// Time complexity: O(n+m)
// Space complexity: O(n)
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        vector<ListNode*> nodes;
        ListNode* ptr = list1;
        while(ptr){
            nodes.push_back(ptr);
            ptr = ptr->next;
        }
        nodes[a-1]->next = list2;
        ptr = list2;
        while(ptr->next) ptr = ptr->next;
        ptr->next = nodes[b+1];
        return list1;
    }
};