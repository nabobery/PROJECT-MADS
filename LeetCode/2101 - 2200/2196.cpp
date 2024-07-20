// 2196. Create Binary Tree From Descriptions

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

// Solution 1 - By Maintaining Mapping of Node and its Children and Recursion
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    unordered_map<int, array<int, 2>> mp;
    TreeNode* helper(int curr){
        TreeNode* root = new TreeNode(curr);
        if(mp.count(curr)){
            if(mp[curr][0]) root->left = helper(mp[curr][0]);
            if(mp[curr][1]) root->right = helper(mp[curr][1]);
        }
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> children;
        for(auto description: descriptions){
            int p = description[0], c = description[1], l = description[2];
            if(l) mp[p][0] = c;
            else mp[p][1] = c;
            children.insert(c);
        }
        int p;
        for(auto it : mp){
            if(!children.count(it.first)){
                p = it.first;
                break;
            }
        }
        return helper(p);
    }
};

// Solution 2 - By Maintaining Mapping of Node and its TreeNode and Iteration
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;
        for(auto description: descriptions){
            int p = description[0], c = description[1], l = description[2];
            if(!mp.count(p)) mp[p] = new TreeNode(p);
            if(!mp.count(c)) mp[c] = new TreeNode(c);
            if(l) mp[p]->left = mp[c];
            else mp[p]->right = mp[c];
            children.insert(c);
        }
        int p;
        for(auto it : mp){
            if(!children.count(it.first)){
                p = it.first;
                break;
            }
        }
        return mp[p];
    }
};
