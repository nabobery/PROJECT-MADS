// 865. Smallest Subtree with all the Deepest Nodes

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

// Solution 1: DFS to get the depth of each node and then find the LCA of deepest nodes
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    map<int, unordered_set<int>> depthToNodes;
    TreeNode* res = NULL;
    void findDepthOfTree(TreeNode* root, int depth){
        if(root->left) findDepthOfTree(root->left, depth+1);
        if(root->right) findDepthOfTree(root->right, depth+1);
        depthToNodes[depth].insert(root->val);
    }
    int findLCAOfDeepestLeaves(TreeNode* root, int maxDepth){
        if(!root) return 0;
        int l = findLCAOfDeepestLeaves(root->left, maxDepth), r = findLCAOfDeepestLeaves(root->right, maxDepth);
        int m = depthToNodes[maxDepth].find(root->val) != depthToNodes[maxDepth].end();
        if(l + r + m >= depthToNodes[maxDepth].size() && res == NULL){
            res = root;
        }
        return l+r+m;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // get depth of each node
        findDepthOfTree(root, 0);
        // get the max depth
        int maxDepth = depthToNodes.rbegin()->first;
        // find LCA of deepest nodes
        findLCAOfDeepestLeaves(root, maxDepth);
        return res;
    }
};

// Solution 2: DFS to get the depth of each node and return the LCA directly
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    pair<TreeNode*, int> helper(TreeNode* root){
        // first: LCA of deepest nodes in this subtree
        // second: depth of this subtree
        // base case
        if(!root) return {root, 0};
        auto left = helper(root->left), right = helper(root->right);

        // if left and right have same depth, then root is the LCA
        if(left.second == right.second){
            return {root, left.second+1};
        } 

        // else return the deeper one
        if(left.second > right.second){
            return {left.first, left.second+1};
        }
        return {right.first, right.second+1};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return helper(root).first;
    }
};