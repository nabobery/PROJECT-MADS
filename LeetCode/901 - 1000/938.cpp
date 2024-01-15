// 938. Range Sum of BST
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

// Solution 1 Tree Traversal using helper
class Solution {
public:
    int sum;
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0;
        helper(root,low,high);
        return sum;    
    }
    void helper(TreeNode* root, int low, int high){
        if(root != NULL){
            if(root->val >= low && root->val <= high){
                sum += root->val;
            }
            if(root->val > low)
                helper(root->left, low, high);
            if(root->val < high) 
                helper(root->right, low, high);
        }
    }
};

// Solution 2 Tree Traversal without helper
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        int res = 0;
        if(root->left) res += rangeSumBST(root->left, low, high);
        if(root->val >= low && root->val <= high) res += root->val;
        if(root->right) res += rangeSumBST(root->right, low, high);
        return res;
    }
};

// shorter Solution 2
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        return (root->val >= low && root->val <= high ? root->val : 0) + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

// Solution 3 Iterative
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node){
                if(node->val >= low && node->val <= high) sum += node->val;
                if(node->val > low) st.push(node->left);
                if(node->val < high) st.push(node->right);
            }
        }
        return sum;
    }
};