// 160. Intersection of Two Linked Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// my naive O(m + n) time and O(n) space solution
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        while(headA != NULL){
            s.insert(headA);
            headA = headA->next;
        }
        while(headB != NULL){
            if(s.find(headB) != s.end()){
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};

// Two-Pointers O(m+n) time and O(1) space solution
// Example: A: 4->1->8->4->5 B : 5->6->1->8->4->5 intersection at 8
// A + B = 4->1->8->4->5->5->6->1->(8)->4->5
// B + A = 5->6->1->8->4->5->4->1->(8)->4->5
// if there is intersection we return intersection, else we reach the end and return NULL
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA, *ptr2 = headB;
        while(ptr1 != ptr2){
            // if still in linkedlist A continue else start from B
            ptr1 = ptr1?ptr1->next:headB;
            // if still in linkedlist B continue else start from A
            ptr2 = ptr2?ptr2->next:headA;
        }
        return ptr1;
    }
};

// Length Difference O(m+n) time and O(1) space solution
// we find the length difference then traverse the longer list by t steps and check if there is any intersection, if we get we return it else NULL
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = 0;
        int m = 0;
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        while(ptr1 != NULL){
            n++;
            ptr1 = ptr1 -> next;
        }
        while(ptr2 != NULL){
            m++;
            ptr2 = ptr2 -> next;
        }
        int t = abs(n - m);
        if(n > m){
            while(t){
                headA = headA -> next;
                t--;
            }
        }
        else{
            while(t){
                headB = headB -> next;
                t--;
            }
        }
        while(headA != NULL and headB != NULL){
            if(headA == headB){
                return headA;
            }
            headA = headA -> next;
            headB = headB -> next;
        }
        return NULL;
    }
};
