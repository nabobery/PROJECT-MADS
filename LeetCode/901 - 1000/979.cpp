// 979. Distribute Coins in Binary Tree

// Solution 1 using DFS
// The basic idea is to go bottom-up and calculate the number of coins in the current subtree
// We always want to balance the left and right subtrees from the current subtree root because we want to minimize the number of moves
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    
    int dfs(TreeNode* root, int& res) {
        // If the root is null, return 0
        if (!root) return 0;
        // Get the number of coins in the left and right subtrees
        int left = dfs(root->left, res), right = dfs(root->right, res);
        // Add the absolute difference between the left and right subtrees to the result
        // This is the number of moves required to balance the left and right subtrees from the current subtree root
        res += abs(left) + abs(right);
        // Return the number of coins in the current subtree 
        // The number of coins in the current subtree is the sum of the number of coins in the left and right subtrees and the number of coins in the current node minus 1 because every node should have exactly one coin
        return root->val + left + right - 1;
    }
};