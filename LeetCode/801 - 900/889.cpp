// 889. Construct Binary Tree from Preorder and Postorder Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// Solution 1 using Recursion
// Time Complexity: O(n^2)
// Space Complexity: O(n)
// The solution is based on the fact that preorder traversal is Node-LEft-Right and post order traversal is Left-Right-Node.
// We can use this fact to construct the tree recursively.
// We can find the left subtree of the tree by finding the root of the left subtree in the preorder traversal and then finding the left subtree in the postorder traversal.
class Solution {
    public:
        TreeNode* constructFromPrePost(vector<int>& preorder,
                                       vector<int>& postorder) {
            int pre = preorder.size(), post = postorder.size();  
            if(!pre) return NULL;                          
            TreeNode* root = new TreeNode(preorder[0]);
            if (pre == 1)
                return root;
            int left_val = preorder[1];
            int left_index = -1;
            for (int i = 0; i < post; i++) {
                if (postorder[i] == left_val) {
                    left_index = i+1;
                    break;
                }
            }
            vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + left_index + 1),
                        left_postorder(postorder.begin(), postorder.begin() + left_index);
            vector<int> right_preorder(preorder.begin()+left_index+1, preorder.end()), right_postorder(postorder.begin()+left_index, postorder.end());
            root->left = constructFromPrePost(left_preorder, left_postorder); 
            root->right = constructFromPrePost(right_preorder, right_postorder); 
            return root;
        }
};

// Solution 2 using Stack
// Time Complexity: O(n)    
// Space Complexity: O(n)

class Solution {
    public:
        TreeNode* constructFromPrePost(vector<int>& preorder,
                                       vector<int>& postorder) {
            stack<TreeNode*> s;
            TreeNode* root = new TreeNode(preorder[0]);
            s.push(root);
            for (int i = 1, j = 0; i < preorder.size(); ++i) {
                TreeNode* node = new TreeNode(preorder[i]);
                while (s.top()->val == postorder[j]) {
                    s.pop();
                    ++j;
                }
                if (!s.top()->left)
                    s.top()->left = node;
                else
                    s.top()->right = node;
                s.push(node);
            }
            return root;
        }
};