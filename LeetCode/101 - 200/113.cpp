// 113. Path Sum II
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
 // my naive dfs
class Solution {
public:
    vector<vector<int>> result;
    void dfs(TreeNode* root, int curr, int target, vector<int> path){
        if(!root){
            return;
        }
        curr += root->val;
        path.push_back(root->val);
        if(!root->left && !root->right){
            if(curr == target) result.push_back(path);
            return;
        }
        dfs(root->left,curr,target,path);
        dfs(root->right,curr,target,path);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return result;
        vector<int> path;
        dfs(root,0, targetSum,path);
        return result;
    }
};

// optimised using backtracking
class Solution {
public:
    vector<vector<int>> result;
    void dfs(TreeNode* root,int sum, vector<int>& path){
        if(!root){
            return;
        }
        path.push_back(root->val);
        if(!root->left && !root->right && sum == root->val){
            result.push_back(path);
        }
        dfs(root->left,sum - root->val,path);
        dfs(root->right,sum - root->val,path);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return result;
        vector<int> path;
        dfs(root,targetSum,path);
        return result;
    }
};
