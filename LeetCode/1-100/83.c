/* Name :  Remove Duplicates from Sorted List 
Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
Return the linked list sorted as well.
Example 1 :
Input: head = [1,1,2]
Output: [1,2]
Example 2 : 
Input: head = [1,1,2,3,3]
Output: [1,2,3]
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
   struct ListNode *ptr = head;  
   while (ptr != NULL && ptr->next != NULL) {
        if (ptr->next->val == ptr->val){
            ptr->next = ptr->next->next;
        }
        else {
            ptr = ptr->next;
        }
   }
   return head; 
};