// 2265. Count Nodes Equal to Average of Subtree

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

// Solution 1 using DFS
// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    int result = 0;
    pair<int,int> helper(TreeNode* root, pair<int,int> p){
        if(!root) return p;
        pair<int,int> p1 = {0,0}, p2 = {0,0};
        if(root->left){
            p1 = helper(root->left, p);

        }
        if(root->right){
            p2 = helper(root->right, p);
        }
        p.first = p.first+p1.first+p2.first+1;
        p.second = p.second+p1.second+p2.second+root->val;
        if(root->val == p.second/p.first) result++;
        return p;
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root, {0,0});
        return result;
    }
};

// A better written Solution 1
class Solution {
public:
    int result = 0;
    pair<int,int> helper(TreeNode* root){
        if(!root) return {0,0};
        pair<int,int> p1 = helper(root->left);
        pair<int,int> p2 = helper(root->right);
        int sum = p1.second+p2.second+root->val;
        int count = p1.first+p2.first+1;
        if(root->val == sum/count) result++;
        return {count, sum};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return result;
    }
};