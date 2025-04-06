// 1123. Lowest Common Ancestor of Deepest Leaves

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

// Solution 1: Using LCA Logic
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
    public:
        map<int, set<int>> depthToNodes;
        TreeNode* res = NULL;
        int mx;
        void dfs(TreeNode* root, int depth){
            if(!root) return;
            depthToNodes[depth].insert(root->val);
            dfs(root->left, depth+1);
            dfs(root->right, depth+1);
        }
        int helper(TreeNode* root, int& h){
            if(!root) return 0;
            int l = helper(root->left, h), r = helper(root->right, h);
            int m = depthToNodes[h].find(root->val) != depthToNodes[h].end();
            if(l + r + m >= depthToNodes[h].size() && !res)
                res = root;
            return l+r+m;
        }
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            // fina the nodes and their depths
            dfs(root, 0);
            // find the deepest leaves
            mx = depthToNodes.rbegin()->first;
            // find the LCA of deepest leaves
            helper(root, mx);
            return res;
        }
};

// Solution 2: Smart DFS
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
    public:
        // Helper function to return both the node and its depth
        pair<TreeNode*, int> dfs(TreeNode* root) {
            if (!root) return {nullptr, 0}; // If the node is null, return depth 0
            
            // Recursively call the left and right subtrees
            auto left = dfs(root->left);
            auto right = dfs(root->right);
            
            // If the left and right subtree depths are equal, the current node is the LCA
            if (left.second == right.second) {
                return {root, left.second + 1}; // Current node is LCA for this depth
            }
            
            // If left subtree is deeper, propagate the left child
            if (left.second > right.second) {
                return {left.first, left.second + 1};
            }
            
            // If right subtree is deeper, propagate the right child
            return {right.first, right.second + 1};
        }
    
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            // Call the DFS helper function starting from the root
            return dfs(root).first;
        }
};