// 382. Linked List Random Node
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
/**
* Your Solution object will be instantiated and called as such:
* Solution* obj = new Solution(head);
* int param_1 = obj->getRandom();
*/
 // Naive sol O(n) time and space
class Solution {
public:
    vector<int> arr;
    Solution(ListNode* head) {
        while(head != NULL){
            arr.push_back(head->val);
            head =  head->next;
        }
    }

    int getRandom() {
        int index = rand()%(arr.size());
        return arr[index];
    }
};

//using reservoir sampling which takes O(1) space and O(n) time
class Solution {
public:
    ListNode* ptr;
    Solution(ListNode* head) {
        ptr =  head;
    }

    int getRandom() {
        int i = 1, result = 0;
        ListNode* curr = ptr;
        while(curr != NULL){
            if(rand()%i == 0)
                result = curr->val;
            i++;
            curr = curr->next;
        }
        return result;
    }
};
