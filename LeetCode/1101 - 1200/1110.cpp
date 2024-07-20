// 1110. Delete Nodes And Return Forest

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

// Solution 1 - Using DFS (Postorder traversal)
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // Convert to_delete vector to set for faster lookup
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;
        // Call dfs function to delete nodes and return forest
        dfs(root, to_delete_set, res, true);
        return res;
    }
    // Recursive function to delete nodes and return forest
    TreeNode* dfs(TreeNode* root, unordered_set<int>& to_delete_set, vector<TreeNode*>& res, bool is_root) {
        // Base case - if root is null, return null
        if (!root) return nullptr;
        // Check if root is to be deleted
        bool deleted = to_delete_set.count(root->val);
        // If root should not be deleted and it is root of tree, add it to result
        if (is_root && !deleted) res.push_back(root);
        // Recursively call dfs function for left and right children
        root->left = dfs(root->left, to_delete_set, res, deleted);
        root->right = dfs(root->right, to_delete_set, res, deleted);
        // Return null if root is to be deleted
        return deleted ? nullptr : root;
    }
};
