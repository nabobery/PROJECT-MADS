// 106. Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        stack<TreeNode*> stk;
        set<TreeNode*> s;
        TreeNode* root = NULL;
        for(int p = n - 1, i = n - 1; p >= 0;){
            TreeNode* node = NULL;
            do{
                node = new TreeNode(postorder[p]);
                if(root == NULL){
                    root = node;
                }
                if(stk.size() > 0){
                    if(s.find(stk.top()) != s.end()){
                        s.erase(stk.top());
                        stk.top()->left = node;
                        stk.pop();
                    }
                    else{
                        stk.top()->right = node;
                    }
                }
                stk.push(node);
            } while(postorder[p--] != inorder[i] && p >=0);
            node = NULL;
            while(stk.size() > 0 && i >= 0 && stk.top()->val == inorder[i]){
                node = stk.top();
                stk.pop();
                i--;
            }
            if(node != NULL){
                s.insert(node);
                stk.push(node);
            }
            
        }
        return root;
    }
};