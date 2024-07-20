// 1530. Number of Good Leaf Nodes Pairs

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

// Solution 1 using DFS from leaf nodes
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>> adj;
    unordered_set<TreeNode*> nodes;
    void helper(TreeNode* root){
        if(!root->left && !root->right){
            nodes.insert(root);
            return;
        }
        if(root->left){
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            helper(root->left);
        }
        if(root->right){
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            helper(root->right);
        }
    }
    void dfs(TreeNode* node, unordered_set<TreeNode*>& visited, int& distance, int& res){
        if(visited.size() > distance) return;
        if(!visited.empty() && nodes.count(node)){
            res++;
            return;
        }
        visited.insert(node);
        for(auto n : adj[node])
            if(!visited.count(n)) dfs(n, visited, distance, res);
        visited.erase(node);
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_set<TreeNode*> visited;
        helper(root);
        int res = 0;
        for(auto node : nodes)
            dfs(node, visited, distance, res);
        return res/2;
    }
};

// Solution 2 using BFS from leaf nodes
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>> adj;
    unordered_set<TreeNode*> nodes;
    void helper(TreeNode* root){
        if(!root->left && !root->right){
            nodes.insert(root);
            return;
        }
        if(root->left){
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            helper(root->left);
        }
        if(root->right){
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            helper(root->right);
        }
    }
    int countPairs(TreeNode* root, int distance) {
        helper(root);
        int res = 0;
        for(auto node : nodes){
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;
            q.push(node);
            visited.insert(node);
            for(int i = 0; i <= distance; i++){
                int size = q.size();
                for(int j = 0; j < size; j++){
                    TreeNode* curr = q.front();
                    q.pop();
                    if(nodes.count(curr) && node != curr) res++;
                    for(auto n : adj[curr])
                        if(!visited.count(n)){
                            q.push(n);
                            visited.insert(n);
                        }
                }
            }
        }
        return res/2;
    }
};

// Solution 3 using Postorder DFS
// Time Complexity: O(n*d^2)
// Space Complexity: O(h)
class Solution {
public:
    int res = 0;
    // do dfs in postorder so that we traverse LCA of all pairs of leaf nodes
    vector<int> dfs(TreeNode* root, int distance){
        // dist[i] stores the number of nodes at distance i from the current node
        vector<int> dist(distance+1, 0);
        // if the current node is null, return the dist array
        if(!root) return dist;
        // if the current node is a leaf node, then there is only one node at distance 1 from it
        if(!root->left && !root->right){
            dist[1] = 1;
            return dist;
        }
        // get the number of nodes at distance i from the left and right child of the current node
        vector<int> left = dfs(root->left, distance);
        vector<int> right = dfs(root->right, distance);
        // for each pair of leaf nodes at distance i and j from the left and right child of the current node, the distance between them should be less than distance
        for(int i = 1; i <= distance; i++)
            for(int j = 1; j <= distance-i; j++)
                res += left[i]*right[j];
        // for each node at distance i from the left and right child of the current node, there is a node at distance i+1 from the current node
        for(int i = 1; i < distance; i++)
            dist[i+1] = left[i]+right[i];
        return dist;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return res;
    }
};