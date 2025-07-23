// 21. Merge Two Sorted Lists
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
 // My Naive iterative Solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode *head;
        if(list1->val < list2->val){
            head = list1;
            list1 = list1->next;
        }
        else{
            head = list2;
            list2 = list2->next;
        }
        ListNode* ptr = head;
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                ptr->next = list1;
                list1 = list1->next;
            }
            else{
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        if (list1 != NULL){
            ptr->next = list1;
        }
        if (list2 != NULL){
            ptr->next = list2;
        }
        return head;
    }
};

// iterative solution using dummy head
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0), *ptr = &dummy;
        while(list1 || list2){
            if(list1 && list2){
                if(list1->val < list2->val) ptr->next = list1, list1=list1->next;
                else ptr->next = list2, list2=list2->next;
            }else if(list1) ptr->next = list1, list1=list1->next;
            else if(list2) ptr->next = list2, list2=list2->next;
            ptr=ptr->next;
        }
        return dummy.next;
    }
};

// recursion solution
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 || !list2) return !list1 ? list2 : list1;
        else if (list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
    }
};

