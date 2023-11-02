// 501. Find Mode in Binary Search Tree

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


// Solution 1 Using Hashmap and DFS
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    unordered_map<int,int> mp;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        mp[root->val]++;
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        int mode = 0;
        for(auto it : mp)
            if(it.second > mode) mode = it.second;
        vector<int> res;
        for(auto it : mp)
            if(it.second == mode) res.push_back(it.first);
        return res;
    }
};

// Solution 2 Using Hashmap and BFS
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            mp[curr->val]++;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        int mode = 0;
        for(auto it : mp)
            if(it.second > mode) mode = it.second;
        vector<int> res;
        for(auto it : mp)
            if(it.second == mode) res.push_back(it.first);
        return res;
    }
};

// Solution 3 Using Hashmap and Iterative Inorder Traversal
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            mp[curr->val]++;
            curr = curr->right;
        }
        int mode = 0;
        for(auto it : mp)
            if(it.second > mode) mode = it.second;
        vector<int> res;
        for(auto it : mp)
            if(it.second == mode) res.push_back(it.first);
        return res;
    }
};

// Solution 4 Using No Extra Space and Morris Inorder Traversal
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        int count = 0, maxCount = 0, currNum = 0;
        while(curr){
            if(curr->left){
                TreeNode* friendNode = curr->left;
                while(friendNode->right) 
                    friendNode = friendNode->right;
                friendNode->right = curr;
                TreeNode* left = curr->left;
                curr->left = NULL;
                curr = left;
            }
            else{
                if(currNum == curr->val) count++;
                else{
                    currNum = curr->val;
                    count = 1;
                }
                if(count > maxCount){
                    res = {};
                    maxCount = count;
                }
                if(count == maxCount)
                    res.push_back(currNum);
                curr = curr->right;
            }
        }
        return res;
    }
};