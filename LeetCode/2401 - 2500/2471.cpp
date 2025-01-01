// 2471. Minimum Number of Operations to Sort a Binary Tree by Level

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

// Solution 1 using BFS and getting minimum swaps for each level
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty()){
            int s = q.size();
            vector<pair<int,int>> v(s);
            for(int i = 0; i < s;i++){
                auto node = q.front();
                q.pop();
                v[i] = {node->val, i};
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            sort(v.begin(), v.end());
            vector<bool> visited(s, false);
            int swaps = 0;
            for (int i = 0; i < s; i++) {
                if (visited[i] || v[i].second == i) 
                    continue;
                int cycle_size = 0;
                int j = i;
                while (!visited[j]) {
                    visited[j] = true;
                    j = v[j].second;
                    cycle_size++;
                }
                if (cycle_size > 1) 
                    swaps += (cycle_size - 1);
            }
            res += swaps;
        }
        return res;
    }
};