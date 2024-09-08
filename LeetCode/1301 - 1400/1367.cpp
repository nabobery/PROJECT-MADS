// 1367. Linked List in Binary Tree

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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */ 

// Solution 1: Brute Force DFS by generating all paths from the tree and checking if the linked list is a subpath of any of the paths
// Time complexity: O(n*m)
// Space complexity: O(n)
class Solution {
public:
    vector<vector<int>> paths;
    int n;
    void dfs(TreeNode* root, vector<int>& curr){
        if(!root->left && !root->right){
            curr.push_back(root->val);
            if(curr.size() >= n) paths.push_back(curr);
            curr.pop_back();
            return;
        }
        curr.push_back(root->val);
        if(root->left) dfs(root->left, curr);
        if(root->right) dfs(root->right, curr);
        curr.pop_back();
    }
    bool helper(vector<int>& haystack, vector<int>& needle) {
        if (needle.empty()) return true;
        if (haystack.size() < needle.size()) return false;
        auto it = std::search(haystack.begin(), haystack.end(), needle.begin(), needle.end());
        return it != haystack.end();
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        ListNode* ptr = head;
        vector<int> list_path, curr;
        while(ptr){
            list_path.push_back(ptr->val);
            ptr = ptr->next;
        }
        n = list_path.size();
        dfs(root, curr);
        for(auto path : paths)
            if(helper(path, list_path)) return true;
        return false;
    }
};

// Solution 2: Optimized DFS by checking if the linked list is a subpath of the tree while traversing the tree
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool dfs(ListNode* head, TreeNode* root){
        if(!head) return true;
        if(!root) return false;
        if(head->val != root->val) return false;
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};