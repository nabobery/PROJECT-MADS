// 1339. Maximum Product of Splitted Binary Tree

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

// Solution 1: Calculate subtree sums using DFS and use BFS to find max product
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    const int mod = 1e9+7;
    unordered_map<TreeNode*, int> nodeToSum;
    int calculateSubtreeSum(TreeNode* root){
        int sum = 0;
        if(root->left) sum += calculateSubtreeSum(root->left);
        if(root->right) sum += calculateSubtreeSum(root->right);
        return nodeToSum[root] = sum + root->val;
    }
    int checkMaxSumBFS(TreeNode* root){
        long res = 0, totalSum = nodeToSum[root];
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr->left){
                res = max(res, (totalSum - nodeToSum[curr->left]) * nodeToSum[curr->left]);
                q.push(curr->left);
            }
            if(curr->right){
                res = max(res, (totalSum - nodeToSum[curr->right]) * nodeToSum[curr->right]);
                q.push(curr->right);
            }
        }
        return res % mod;
    }
    int maxProduct(TreeNode* root) {
        calculateSubtreeSum(root);
        return checkMaxSumBFS(root);
    }
};