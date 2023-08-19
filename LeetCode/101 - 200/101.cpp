// 101. Symmetric Tree

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

// Solution1 

class Solution {
public:
    unordered_map<int,vector<int>> mp;
    void helper(TreeNode* root, int level){
        if(!root){
            mp[level].push_back(101);
            return;
        }
        mp[level].push_back(root->val);
        helper(root->left, level+1);
        helper(root->right, level+1);
    }
    
    bool isSymmetric(TreeNode* root) {
        helper(root, 0);
        for(int i = 1;i < mp.size();i++){
            for(int j = 0; j < mp[i].size()/2;j++){
                if(mp[i][j] != mp[i][mp[i].size() - j - 1]) return false;
            }
        }
        return true;
    }
};

// Solution 2
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        vector<int> arr;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        TreeNode* curr;
        while(q.size() > 1){
            curr = q.front();
            q.pop();
            if(!curr){
                for(int i = 0; i < arr.size()/2;i++){
                    if(arr[i] != arr[arr.size() - i - 1]) return false;
                }
                q.push(NULL);
                arr.clear();
            }
            else{
                if(curr->left){
                    q.push(curr->left);
                }
                else if(!curr->left && curr->val != 101){
                    q.push(new TreeNode(101));
                }
                if(curr->right){
                    q.push(curr->right);
                }
                else if(!curr->right && curr->val != 101){
                    q.push(new TreeNode(101));
                }
                arr.push_back(curr->val);
            }
        }
        return true;
    }
};