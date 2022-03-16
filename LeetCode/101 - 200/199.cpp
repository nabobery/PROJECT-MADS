// 199. Binary Tree Right Side View
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
 // my naive solution by getting last element of level order traversal
class Solution {
public:
    vector<int> temp;
    void addCurrentLevel(TreeNode* root, int level){
        if(root == NULL) return;
        if(level == 1) temp.push_back(root->val);
        else if(level > 1){
            addCurrentLevel(root->left,level-1);
            addCurrentLevel(root->right,level-1);
        }
    }
    int height(TreeNode* root){
        if(root == NULL) return 0;
        else{
            int lheight = height(root->left);
            int rheight = height(root->right);
            return (max(lheight,rheight)+1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        int h = height(root);
        for(int i = 1; i <= h;i++){
            addCurrentLevel(root,i);
            result.push_back(temp.back());
            temp.clear();
        }
        return result;
    }
};

// using dfs
class Solution {
public:
    void dfs(TreeNode* root, int level, vector<int>& result){
        if(!root) return;
        if(result.size() < level) result.push_back(root->val);
        dfs(root->right,level+1,result);
        dfs(root->left,level+1,result);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        dfs(root,1,result);
        return result;
    }
};

// using BFS O(n) time and O(logn) solution
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            result.push_back(q.back()->val);
            for(int i= q.size(); i > 0;i--){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return result;
    }
};

