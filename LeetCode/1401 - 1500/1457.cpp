// 1457. Pseudo-Palindromic Paths in a Binary Tree

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

// Solution 1 using DFS and BackTracking
// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    int res;
    void helper(TreeNode* root, vector<int>& digits){
        if(!root->left && !root->right){
            digits[root->val]++;
            int odd = 0;
            for(int cnt : digits)
                if(cnt%2) odd++;
            if(odd <= 1) res++;
            digits[root->val]--;
            return;
        }
        digits[root->val]++;
        if(root-> left) helper(root->left, digits);
        if(root->right) helper(root->right, digits);
        digits[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> digits(10, 0);
        res = 0;
        helper(root, digits);
        return res;
    }
};

// Solution 2 using DFS and Bit Manipulation
// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    int res;
    void helper(TreeNode* root, int digits){
        if(!root->left && !root->right){
            digits ^= (1 << root->val);
            if(digits == 0 || (digits & (digits-1)) == 0) res++;
            return;
        }
        digits ^= (1 << root->val);
        if(root-> left) helper(root->left, digits);
        if(root->right) helper(root->right, digits);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        res = 0;
        helper(root, 0);
        return res;
    }
};