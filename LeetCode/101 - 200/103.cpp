// 103. Binary Tree Zigzag Level Order Traversal
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
// my naive O(n^2) time and O(n) space solution
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        int h = height(root);
        for(int i = 1; i <= h;i++){
            addCurrentLevel(root,i);
            if(i % 2){
                result.push_back(temp);
            }
            else{
                reverse(temp.begin(),temp.end());
                result.push_back(temp);
            }
            temp.clear();
        }
        return result;
    }
};

// using BFS and Queue
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                // find position to fill node's value if we should go reverse or go normal
                int index = (leftToRight) ? i : (size - 1 - i);
                temp[index] = node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            // after traversing the current level
            leftToRight = !leftToRight;
            result.push_back(temp);
        }
        return result;
    }
};
