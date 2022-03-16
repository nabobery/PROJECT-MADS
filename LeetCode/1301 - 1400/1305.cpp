// 1305. All Elements in Two Binary Search Trees
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
 // N is number of nodes combined of 2 trees
// my naive solution by traversing using dfs and then sorting O(NlogN) time and O(N) space solution
class Solution {
public:
    vector<int> result;
    void helper(TreeNode* root){
        if(root == NULL)
            return;
        result.push_back(root->val);
        if(root-> left != NULL)
            helper(root->left);
        if(root->right != NULL)
            helper(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        helper(root1);
        helper(root2);
        sort(result.begin(),result.end());
        return result;
    }
};

// using stack and making use of BST property O(N) time and space solution
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        stack<TreeNode *> stk1, stk2;
        while(root1 || root2 || !stk1.empty() || !stk2.empty()){
            while(root1){
                stk1.push(root1);
                root1 = root1->left;
            }
            while(root2){
                stk2.push(root2);
                root2 = root2->left;
            }
            if(stk2.empty() || (!stk1.empty() && stk1.top()->val <= stk2.top()->val)){
                root1 = stk1.top();
                stk1.pop();
                result.push_back(root1->val);
                root1 = root1->right;

            }
            else{
                root2 = stk2.top();
                stk2.pop();
                result.push_back(root2->val);
                root2 = root2->right;
            }
        }
        return result;
    }
};
