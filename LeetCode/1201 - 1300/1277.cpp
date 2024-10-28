// 1277. Count Square Submatrices with All Ones

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

// Solution 1 using DFS, BFS and Hashmap (TLE)
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    unordered_map<int,int> levelsum;
    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int curr = 0;
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto node = q.front();
                q.pop();
                curr += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            levelsum[level++] = curr;
        }
    }

    void helper(TreeNode* node, int sum, int level) {
        if (!node) return;
        node->val = levelsum[level] - sum;
        int leftSum = node->left ? node->left->val : 0;
        int rightSum = node->right ? node->right->val : 0;
        helper(node->left, leftSum + rightSum, level + 1);
        helper(node->right, leftSum + rightSum, level + 1);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        bfs(root);
        helper(root, 0, 0);
        root->val = 0;
        return root;
    }
};

// Solution 2 using 2 BFS and vector
// 1st BFS to calculate the sum of each level
// 2nd BFS to update the value of each node
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> levelsum;
        queue<TreeNode*> q;
        q.push(root);
        // 1st BFS to calculate the sum of each level
        while(!q.empty()){
            int curr = 0;
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto node = q.front();
                q.pop();
                curr += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            levelsum.push_back(curr);
        }

        // 2nd BFS to update the value of each node
        root->val = 0;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto node = q.front();
                q.pop();
                int leftSum = node->left ? node->left->val : 0;
                int rightSum = node->right ? node->right->val : 0;
                if(node->left){
                    node->left->val = levelsum[level] - leftSum - rightSum;
                    q.push(node->left);
                }
                if(node->right){
                    node->right->val = levelsum[level] - leftSum - rightSum;
                    q.push(node->right);
                }
            }
            level++;
        }
        return root;
    }
};
