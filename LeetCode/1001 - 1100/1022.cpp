// 1022. Sum of Root To Leaf Binary Numbers
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

// Solution 1: My naive solution with string concatenation and binary to decimal conversion
// Time complexity: O(n * h) where n is number of nodes and h is height of tree (due to string concatenation and conversion)
// Space complexity: O(h) due to recursion stack and path string
class Solution {
public:
    int sum;
    int bintodeci(string bin){
        int result = 0;
        int base = 1;
        for(int i = bin.size() - 1; i >= 0;i--){
            if(bin[i] == '1')
                result += base;
            base = base*2;
        }
        return result;
    }
    int sumRootToLeaf(TreeNode* root) {
        sum = 0;
        string path = "";
        helper(root, path);
        return sum;

    }
    void helper(TreeNode *node, string path){
        if(node == NULL){
            return;
        }
        path += (node->val + '0');
        if(node->left == NULL && node->right == NULL){
            sum += bintodeci(path);
        }
        else{
            helper(node->left,path);
            helper(node->right,path);
        }

    }
};

// Solution 2: Optimized solution using bit manipulation to avoid string concatenation and conversion
// Time complexity: O(n) where n is number of nodes (each node is visited once)
// Space complexity: O(h) due to recursion stack
class Solution {
public:
    int sum = 0;
    int sumRootToLeaf(TreeNode* root) {
        helper(root, 0);
        return sum;

    }
    void helper(TreeNode *node, int curr){
        if(node != NULL){
            curr = (curr << 1) | node->val;
            if(node->left == NULL && node->right == NULL)
                sum += curr;
            helper(node->left, curr);
            helper(node->right,curr);
        }
    }
};

// Solution 3: Morris Traversal to achieve O(1) space complexity (excluding output)
// Time complexity: O(n) where n is number of nodes (each node is visited at most twice)
// Space complexity: O(1) excluding output (no recursion stack or extra data structures used
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0, curr = 0;
        int steps;
        TreeNode *prev;
        while(root != NULL){
            if(root->left != NULL){
                prev = root->left;
                steps = 1;
                while(prev->right != NULL && prev->right != root){
                    prev = prev->right;
                    ++steps;
                }
                if(prev->right == NULL){
                    curr = (curr << 1) | root->val;
                    prev->right = root;
                    root = root->left;
                }
                else{
                    if(prev->left == NULL){
                        sum += curr;
                    }
                    for(int i = 0; i < steps; i++){
                        curr >>= 1;
                    }
                    prev->right = NULL;
                    root = root->right;
                }
            }
            else{
                curr = (curr << 1) | root->val;
                if(root->right == NULL)
                    sum += curr;
                root = root->right;
            }

        }
        return sum;
    }
};

// Solution 4: DFS with backtracking to achieve O(h) space complexity (due to recursion stack)
// Time complexity: O(n) where n is number of nodes (each node is visited once
// Space complexity: O(h) due to recursion stack
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int currentPathValue = 0;
        return backtrack(root, currentPathValue);
    }

private:
    int backtrack(TreeNode* node, int& currentPathValue) {
        if (!node) return 0;

        currentPathValue = (currentPathValue << 1) | node->val;

        if (!node->left && !node->right) {
            int leafValue = currentPathValue;
            currentPathValue >>= 1;
            return leafValue;
        }

        int totalSum = backtrack(node->left, currentPathValue) + 
                       backtrack(node->right, currentPathValue);

        currentPathValue >>= 1;
        return totalSum;
    }
};
