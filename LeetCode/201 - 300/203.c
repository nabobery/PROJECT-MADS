/* Name : Remove Linked List Elements
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has 
Node.val == val, and return the new head.
Example 1 : 
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2 : 
Input: head = [7,7,7,7], val = 7
Output: []
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    if (!head)
        return head;
	struct ListNode *ptr = head->next;
    struct ListNode *prev = head;
    while (ptr)
    {
        if (ptr->val == val)
        {
            prev->next = ptr->next;
            ptr = ptr->next;
            continue;
        }    
        prev = ptr;
        ptr = ptr->next;
    }
    if (head->val == val)
        head = head->next;
    return head;    
}

/* My failed Code :
    struct ListNode *ptr = head;
    struct ListNode *prev = NULL;   
    struct Listnode *temp = NULL; 
    while (ptr != NULL && ptr->next != NULL){
        prev = ptr;
        ptr = ptr->next;
        if (ptr->val == val){
            temp = ptr->next;
            free(ptr);
            prev->next = temp;
            ptr = prev;  
        }
    }
    return head;
    */
