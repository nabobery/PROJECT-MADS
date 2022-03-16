/* 404. Sum of Left Leaves
Given the root of a binary tree, return the sum of all left leaves.
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
Example 2:
Input: root = [1]
Output: 0

Constraints:
The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000

*/

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
    int sumOfLeftLeaves(TreeNode* root) {
        int total = 0;
        if(root != NULL){
            if(isLeaf(root->left)){
                total += root->left->val;
            }
            else {
                total += sumOfLeftLeaves(root->left);
            }
            total += sumOfLeftLeaves(root->right);
        }
        return total;
    }
    bool isLeaf(TreeNode* node){
        if(node == NULL)
            return false;
        if(node->left == NULL && node->right == NULL){
            return true;
        }
        return false;
    }
};