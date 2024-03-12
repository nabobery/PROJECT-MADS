// 1609. Even Odd Tree

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

// Solution 1 using Level Order Traversal without using extra space for storing level order traversal
// Time complexity: O(n)
// Space complexity: O(n) 

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        int prev, curr, level = 0;
        TreeNode* temp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            temp = q.front();
            prev = temp->val;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            q.pop();
            if(level%2){
                if(prev%2) return false;
                for(int i = 1; i < s;i++){
                    temp = q.front();
                    curr = temp->val;
                    q.pop();
                    if(prev <= curr || curr%2) return false;
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                    prev = curr;
                }
            }
            else{
                if(prev%2 == 0) return false;
                for(int i = 1; i < s;i++){
                    temp = q.front();
                    curr = temp->val;
                    q.pop();
                    if(prev >= curr || curr%2 == 0) return false;
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                    prev = curr;
                }
            }
            level++;
        }
        return true;
    }
};

// Solution 2 using Level Order Traversal using extra space for storing level order traversal (cleaner code)
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        int l = 0;
        while(!q.empty()){
            int s = q.size();
            level.clear();
            for(int i = 0; i < s; i++){
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(l%2){
                if(level[0]%2) return false;
                for(int i = 1; i < level.size(); i++)
                    if(level[i]%2 || level[i] >= level[i-1]) return false;
            }
            else{
                if(level[0]%2 == 0) return false;
                for(int i = 1; i < level.size(); i++)
                    if(level[i]%2 == 0 || level[i] <= level[i-1]) return false;
            }
            l++;
        }
        return true;
    }
};