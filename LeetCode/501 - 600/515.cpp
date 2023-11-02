// 515. Find Largest Value in Each Tree Row

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

// Solution 1 using BFS
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        while(!q.empty()){
            int sz = q.size(), ma = INT_MIN;
            for(int i = 0; i < sz;i++){
                temp = q.front();
                q.pop();
                ma = max(ma, temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            res.push_back(ma);
        }
        return res;
    }
};

// Solution 2 using DFS Recursion
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> res;
    void dfs(TreeNode* root, int level){
        if(!root) return;
        if(res.size() == level) res.push_back(root->val);
        else res[level] = max(res[level], root->val);
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};