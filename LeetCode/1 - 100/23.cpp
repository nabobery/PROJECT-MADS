// 23. Merge k Sorted Lists
#include "iostream"
#include "vector"
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeLists(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *head;
        if(l1->val < l2->val){
            head = l1;
            l1 = l1->next;
        }
        else{
            head = l2;
            l2 = l2->next;
        }
        ListNode* ptr = head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                ptr->next = l1;
                l1 = l1->next;
            }
            else{
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        if (l1 != NULL){
            ptr->next = l1;
        }
        if (l2 != NULL){
            ptr->next = l2;
        }
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0)
            return NULL;
        vector<ListNode*> temp;
        while(lists.size() > 1){
            n = lists.size();
            for(int i = 0; i < n;i+=2){
                if(i == n - 1){
                    temp.push_back(lists[i]);
                }
                else{
                    temp.push_back(mergeLists(lists[i], lists[i+1]));
                }
            }
            lists = temp;
            temp.clear();
        }
        return lists[0];
    }
};

int main{
    Solution obj;

    return 0;
};
