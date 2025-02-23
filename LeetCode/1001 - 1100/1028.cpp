// 1028. Recover a Tree From Preorder 


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

// Solution 1: Using Iterative DFS
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
    public:
        TreeNode* recoverFromPreorder(string traversal) {
            unordered_map<int, TreeNode*> depthToCurrentParent;
            int depth = 0, i = 0, n = traversal.size();
            while(i < n){
                int j = i+1;
                while(j < n && traversal[j] != '-') j++;
                int val = stoi(traversal.substr(i, j-i));
                TreeNode* node = new TreeNode(val);
                depthToCurrentParent[depth] = node;
                if(depthToCurrentParent.count(depth-1)){
                    if(!depthToCurrentParent[depth-1]->left) depthToCurrentParent[depth-1]->left = node;
                    else depthToCurrentParent[depth-1]->right = node;
                }
                depth = 0;
                while(j < n && traversal[j] == '-'){
                    depth++;
                    j++;
                }
                i =j;
            }
            return depthToCurrentParent[0];
        }
};