// 2583. Kth Largest Sum in a Binary Tree

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

// Solution 1 using BFS and sorting
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> level_sums;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            long long curr = 0;
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto node = q.front();
                q.pop();
                curr += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level_sums.push_back(curr);
        }
        sort(level_sums.begin(), level_sums.end(), greater<long long>());
        return k > int(level_sums.size()) ? -1 : level_sums[k-1];
    }
};

// Solution 2 using BFS and priority queue
// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> pq;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            long long curr = 0;
            int s = q.size();
            for(int i = 0; i < s;i++){
                auto node = q.front();
                q.pop();
                curr += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            pq.push(curr);
        }
        while(!pq.empty() && k > 1){
            pq.pop();
            k--;
        }
        return pq.empty() ? -1 : pq.top();
    }
};