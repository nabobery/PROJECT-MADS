// 2096. Step-By-Step Directions From a Binary Tree Node to Another

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

// Solution 1: Create an adjacency list and perform DFS
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    unordered_map<int, vector<pair<int, string>>> adj;
    vector<bool> visited;
    void helper(TreeNode* root){
        if(!root) return;
        if(root->left){
            adj[root->val].push_back({root->left->val, "L"});
            adj[root->left->val].push_back({root->val, "U"});
            helper(root->left);
        }
        if(root->right){
            adj[root->val].push_back({root->right->val, "R"});
            adj[root->right->val].push_back({root->val, "U"});
            helper(root->right);
        }
    }
    void dfs(int start, int dest, string& res, string& curr){
        if(start == dest){
            res = curr;
            return;
        }
        visited[start-1] = true;
        for(auto n: adj[start]){
            curr += n.second;
            if(!visited[n.first-1]){
                dfs(n.first, dest, res, curr);
            }
            curr.pop_back();
        }
        visited[start-1] = false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        helper(root);
        string res, curr;
        visited.resize(adj.size(), false);
        dfs(startValue, destValue, res, curr);
        return res;
    }
};

// Solution 2: Finding LCA and then finding the path from start to LCA and LCA to dest
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    TreeNode* lca(TreeNode* root, int p, int q){
        if(!root) return NULL;
        if(root->val == p || root->val == q) return root;
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        if(left && right) return root;
        return left ? left : right;
    }
    bool findPath(TreeNode* root, int target, string& path){
        if(!root) return false;
        if(root->val == target) return true;
        path += 'L';
        if(findPath(root->left, target, path))
            return true;
        path.pop_back();
        path += 'R';
        if(findPath(root->right, target, path))
            return true;
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lcaNode = lca(root, startValue, destValue);
        string startPath, destPath;
        findPath(lcaNode, startValue, startPath);
        findPath(lcaNode, destValue, destPath);
        // start -> LCA is all Us and LCA -> dest is destPath
        string res = string(startPath.size(), 'U');
        res += destPath;
        return res;
    }
};
