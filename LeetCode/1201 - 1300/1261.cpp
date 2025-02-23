// 1261. Find Elements in a Contaminated Binary Tree

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

 /**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

// Solution 1: Using DFS and Unordered Set
// Time Complexity: O(n)
// Space Complexity: O(n)
class FindElements {
    public:
        unordered_set<int> st;
        void helper(TreeNode* root, int val){
            if(!root) return;
            st.insert(val);
            if(root->left != NULL) helper(root->left, 2*val + 1);
            if(root->right != NULL) helper(root->right, 2*val + 2);
        }
        FindElements(TreeNode* root) {
            helper(root, 0);
        }
        
        bool find(int target) {
            return st.find(target) != st.end();
        }
    };

// Solution 2: Using DFS and Bit Manipulation
// Time Complexity: O(n)
// Space Complexity: O(n)
class FindElements {
    public:
        TreeNode* root;
        void helper(TreeNode* root, int val){
            if(!root) return;
            root->val = val;
            if(root->left != NULL) helper(root->left, 2*val + 1);
            if(root->right != NULL) helper(root->right, 2*val + 2);
        }
        FindElements(TreeNode* root) {
            this->root = root;
            helper(root, 0);
        }
        
        bool find(int target) {
            int val = target;
            TreeNode* node = root;
            stack<int> st;
            while(val > 0){
                st.push(val);
                val = (val - 1) / 2;
            }
            while(!st.empty()){
                int top = st.top();
                st.pop();
                if(node->left != NULL && node->left->val == top) node = node->left;
                else if(node->right != NULL && node->right->val == top) node = node->right;
                else return false;
            }
            return true;
        }
};
    