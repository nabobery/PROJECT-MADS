// 2415. Reverse Odd Levels of Binary Tree

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

// Solution 1 using BFS traversal twice
// Time Complexity: O(n)
// Space Complexity: O(logn)
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int, vector<int>> mp;
        int level = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto node = q.front();
                q.pop();
                if(level%2) mp[level].push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level%2) reverse(mp[level].begin(), mp[level].end());
            level++;
        }
        level = 0;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto node = q.front();
                q.pop();
                if(level%2) node->val = mp[level][i];
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level++;
        }
        return root;
    }
};

// Solution 2 using BFS traversal once and storing the values in a vector
// Time Complexity: O(n)
// Space Complexity: O(logn)
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int s = q.size();
            vector<TreeNode*> currNodes;
            for(int i = 0; i < s;i++){
                auto node = q.front();
                q.pop();
                if(level%2) currNodes.push_back(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level%2){
                int l = 0, r = currNodes.size()-1;
                while(l < r){
                    swap(currNodes[l]->val, currNodes[r]->val);
                    l++;
                    r--;
                }
            }
            level++;
        }
        return root;
    }
};


// Solution 3 using DFS
// Time Complexity: O(n)
// Space Complexity: O(logn)
class Solution {
public:
    void helper(TreeNode* left, TreeNode* right, int level){
        if(!left || !right) return;
        if(level%2 == 0) swap(left->val, right->val);
        helper(left->left, right->right, level+1);
        helper(left->right, right->left, level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        helper(root->left, root->right, 0);
        return root;
    }
};