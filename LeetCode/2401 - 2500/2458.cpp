// 2458. Height of Binary Tree After Subtree Removal Queries

// Solution 1 using DFS, BFS and Hashmaps
// Time complexity: O(n)
// Space complexity: O(n)
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
class Solution {
public:
    unordered_map<int, int> sub_tree_height;
    unordered_map<int, pair<int, int>> level_to_nodes; 
    unordered_map<int, int> nodes_to_level;

    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                auto node = q.front();
                q.pop();
                int height = sub_tree_height[node->val];
                if(!level_to_nodes.count(level)){
                    level_to_nodes[level].first = height;
                    level_to_nodes[level].second = -1;
                }
                else{
                    auto& maxHeights = level_to_nodes[level];
                    if (height > maxHeights.first) {
                        maxHeights.second = maxHeights.first; 
                        maxHeights.first = height; 
                    } else if (height > maxHeights.second) {
                        maxHeights.second = height;
                    }
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                nodes_to_level[node->val] = level;
            }
            level += 1;
        }
    }

    int helper(TreeNode* root) {
        if (!root) return -1;
        int left = helper(root->left), right = helper(root->right);
        int h = max(left, right) + 1;
        sub_tree_height[root->val] = h;
        return h;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        helper(root);
        int m = queries.size(), h = sub_tree_height[root->val];
        vector<int> res(m);
        bfs(root);
        for (int i = 0; i < m; i++) {
            int new_h = h;
            int level = nodes_to_level[queries[i]];
            int max1 = level_to_nodes[level].first;
            int max2 = level_to_nodes[level].second;
            
            if (max1 == sub_tree_height[queries[i]])
                new_h -= (max1 - max2);
            res[i] = min(new_h, h);
        }
        return res;
    }
};
