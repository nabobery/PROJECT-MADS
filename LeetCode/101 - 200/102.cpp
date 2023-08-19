// 102. Binary Tree Level Order Traversal

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

// Solution using Queue 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> result;
        vector<int> arr;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        TreeNode* curr;
        while(q.size() > 1){
            curr = q.front();
            q.pop();
            if(!curr){
                result.push_back(arr);
                q.push(NULL);
                arr.clear();
            }
            else{
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                arr.push_back(curr->val);
            }
        }
        result.push_back(arr);
        return result;
    }
};