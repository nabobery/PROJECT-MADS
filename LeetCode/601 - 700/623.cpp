// 623. Add One Row to Tree

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* n = new TreeNode(val);
            n->left = root;
            return n;
        }
        int level = 1;
        vector<TreeNode*> prev;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            if(level == depth-1){
                for(int i = 0; i < s;i++){
                    auto curr = q.front();
                    q.pop();
                    prev.push_back(curr);
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
            else if(level == depth){
                for(auto node : prev){
                    TreeNode* left = q.front(); q.pop();
                    node->left =  new TreeNode(val, left, NULL);
                    TreeNode* right = q.front(); q.pop();
                    node->right = new TreeNode(val, NULL, right);
                }
                break;
            }
            else{
                for(int i = 0; i < s;i++){
                    auto curr = q.front();
                    q.pop();
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
            }
            level++;
        }
        return root;
    }
};


// Solution 2 using DFS
// Time complexity: O(n)
// Space complexity: O(h)
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* n = new TreeNode(val);
            n->left = root;
            return n;
        }
        dfs(root, val, depth, 1);
        return root;
    }
    
    void dfs(TreeNode* root, int val, int depth, int level){
        if(!root) return;
        if(level == depth-1){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            root->left = new TreeNode(val, left, NULL);
            root->right = new TreeNode(val, NULL, right);
            return;
        }
        dfs(root->left, val, depth, level+1);
        dfs(root->right, val, depth, level+1);
    }
};