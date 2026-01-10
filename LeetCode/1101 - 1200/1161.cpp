// 1161. Maximum Level Sum of a Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// Solution 1: Using Level Order Traversal (BFS)
// Time Complexity: O(N), where N is the number of nodes in the tree
// Space Complexity: O(M), where M is the maximum number of nodes at any level in the tree
class Solution {
public:
    int maxSum, result;
    void levelWiseSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while (!q.empty()) {
            int sz = q.size();
            int currSum = 0;
            for (int i = 0; i < sz; i++) {
                auto currNode = q.front();
                currSum += currNode->val;
                q.pop();
                if (currNode->left)
                    q.push(currNode->left);
                if (currNode->right)
                    q.push(currNode->right);
            }
            if (currSum > maxSum) {
                maxSum = currSum;
                result = level;
            }
            level++;
        }
    }
    int maxLevelSum(TreeNode* root) {
        maxSum = INT_MIN;
        result = -1;
        levelWiseSum(root);
        return result;
    }
};