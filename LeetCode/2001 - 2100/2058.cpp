// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
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

// Solution 1 using dummy vector
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mi = INT_MAX, mx = 0;
        vector<int> temp, critical;
        ListNode* ptr = head;
        while(ptr){
            temp.push_back(ptr->val);
            ptr = ptr->next;
        }
        for(int i = 1; i < temp.size()-1;i++){
                if((temp[i] > temp[i-1] && temp[i] > temp[i+1]) || (temp[i] < temp[i-1] && temp[i] < temp[i+1])) 
                critical.push_back(i);
        }
        if(critical.size() < 2){
            mi = -1;
            mx = -1;
        }
        else{
            mx = critical.back() - critical[0];
            for(int i=1; i < critical.size();i++) 
                mi = min(critical[i] - critical[i-1], mi);
        }
        return {mi, mx};
    }
};

// Solution 2 without using dummy vector and using 1 variable to store previous value of node and then 2 variables to store the first and previous critical point
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mi = INT_MAX, mx = 0, prev = head->val, first = -1, prev_critical = -1, i = 0;
        ListNode* ptr = head;
        while(ptr){
            if((ptr->val > prev && ptr->next && ptr->val > ptr->next->val) || (ptr->val < prev && ptr->next && ptr->val < ptr->next->val)){
                if(first == -1) first = i;
                if(prev_critical != -1) mi = min(i - prev_critical, mi);
                prev_critical = i;
            }
            prev = ptr->val;
            ptr = ptr->next;
            i++;
        }
        if(prev_critical == -1 || first == prev_critical){
            mi = -1;
            mx = -1;
        }
        else mx = prev_critical - first;
        return {mi, mx};
    }
};