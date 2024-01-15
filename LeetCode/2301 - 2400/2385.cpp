// 2385. Amount of Time for Binary Tree to Be Infected

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

// Solution 1 using BFS twice
// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        queue<pair<TreeNode*,int>> q1;
        if(root->left) q1.push({root->left, root->val});
        if(root->right) q1.push({root->right, root->val});
        int res = 0;
        while(!q1.empty()){
            auto curr = q1.front();
            q1.pop();
            adj[curr.second].push_back(curr.first->val);
            adj[curr.first->val].push_back(curr.second);
            if(curr.first->left) q1.push({curr.first->left, curr.first->val});
            if(curr.first->right) q1.push({curr.first->right, curr.first->val});
        }
        queue<pair<int,int>> q2;
        q2.push({start, 0});
        unordered_set<int> vis;
        while(!q2.empty()){
            auto curr = q2.front();
            q2.pop();
            vis.insert(curr.first);
            for(auto i : adj[curr.first])
                if(!vis.count(i)) q2.push({i, curr.second+1});    
            res = max(res, curr.second);
        }
        return res;
    }
};

// Solution 2 using one pass DFS
// Time complexity: O(N)
// Space complexity: O(N)
class Solution {
public:
    int result = 0;
    int amountOfTime(TreeNode* root, int start) {
        helper(root, start);
        return result;
    }
    int helper(TreeNode* root, int start){
        int depth = 0;  
        if(!root) return depth;
        int left = helper(root->left, start);
        int right = helper(root->right, start);
        if(root->val == start){
            result = max(left, right);
            depth = -1;
        }
        else if(left >= 0 && right >= 0)
            depth = max(left, right)+1;
        else{
            result = max(result, abs(left)+abs(right));
            depth = min(left, right)-1;
        }
        return depth;
    }
};
    