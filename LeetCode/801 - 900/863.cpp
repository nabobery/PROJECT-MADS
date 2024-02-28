// 863. All Nodes Distance K in Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Solution 1 using BFS and conversion of tree to graph using DFS
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    void tree2Graph(int p, TreeNode* root, unordered_map<int, vector<int>>& adj){
        if(!root) return;
        if(root->left) tree2Graph(root->val, root->left, adj);
        if(p != -1){
            adj[root->val].push_back(p);
            adj[p].push_back(root->val);
        }
        if(root->right) tree2Graph(root->val, root->right, adj);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>> adj;
        unordered_set<int> visited;
        tree2Graph(-1, root, adj);
        queue<int> q;
        q.push(target->val);
        visited.insert(target->val);
        int dis = 0;
        while(!q.empty()){
            int s = q.size();
            vector<int> res;
            for(int i = 0; i < s;i++){
                int curr = q.front();
                q.pop();
                res.push_back(curr);
                for(int n : adj[curr]){
                    if(!visited.count(n)){
                        visited.insert(n);
                        q.push(n);
                    }
                }
            }
            if(dis == k) return res;
            dis++;
        }
        return {};
    }
};

// Solution 2 using DFS and conversion of tree to graph using DFS
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    void tree2Graph(int p, TreeNode* root, unordered_map<int, vector<int>>& adj){
        if(!root) return;
        if(root->left) tree2Graph(root->val, root->left, adj);
        if(p != -1){
            adj[root->val].push_back(p);
            adj[p].push_back(root->val);
        }
        if(root->right) tree2Graph(root->val, root->right, adj);
    }
    void dfs(int u, int p, int k, unordered_map<int, vector<int>>& adj, vector<int>& res){
        if(k == 0){
            res.push_back(u);
            return;
        }
        for(int v : adj[u]){
            if(v != p) dfs(v, u, k-1, adj, res);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>> adj;
        tree2Graph(-1, root, adj);
        vector<int> res;
        dfs(target->val, -1, k, adj, res);
        return res;
    }
};
