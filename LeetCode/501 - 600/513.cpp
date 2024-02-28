// 513. Find Bottom Left Tree Value

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

// Solution 1 using Simple DFS 
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    map<int,int> left;
    void dfs(TreeNode* root, int depth){
        if(root->left) dfs(root->left, depth+1);
        if(!left.count(depth)) left[depth] = root->val;
        if(root->right) dfs(root->right, depth+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return left.rbegin()->second;
    }
};

// Solution 2 using BFS (Level Order Traversal)
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            root = q.front();
            q.pop();
            if(root->right) q.push(root->right);
            if(root->left) q.push(root->left);
        }
        return root->val;
    }
};