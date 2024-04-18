// 988. Smallest String Starting From Leaf

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

// Solution 1 using dfs and set
// Time complexity: O(n + hlogh)
// Space complexity: O(n + h)
class Solution {
public:
    set<string> strs;
    void dfs(TreeNode* root, string path){
        path += (root->val + 'a');
        if(!root->left && !root->right){
            reverse(path.begin(), path.end());
            strs.insert(path);
            return;
        }
        if(root->left) dfs(root->left, path);
        if(root->right) dfs(root->right, path);
    }
    string smallestFromLeaf(TreeNode* root) {
        string path = "";
        dfs(root, path);
        return *strs.begin();
    }
};

// Solution 2 using dfs and priority_queue
// Time complexity: O(n + hlogh)
// Space complexity: O(n + h)
class Solution {
public:
    priority_queue<string, vector<string>, greater<string>> pq;
    void dfs(TreeNode* root, string path){
        path += (root->val + 'a');
        if(!root->left && !root->right){
            reverse(path.begin(), path.end());
            pq.push(path);
            return;
        }
        if(root->left) dfs(root->left, path);
        if(root->right) dfs(root->right, path);
    }
    string smallestFromLeaf(TreeNode* root) {
        string path = "";
        dfs(root, path);
        return pq.top();
    }
};

// Solution 3 using dfs and string
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string smallestFromLeaf(TreeNode* root, string path = "") {
        if(!root) return "|";
        path = string(1, 'a' + root->val) + path;
        if(!root->left && !root->right) return path;
        return min(smallestFromLeaf(root->left, path), smallestFromLeaf(root->right, path));
    }
};