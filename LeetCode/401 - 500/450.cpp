// 450. Delete Node in a BST
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
// Very Slow Solution
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return root;
        }
        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else if(root-> val < key){
            root->right = deleteNode(root->right, key);
        }
        else{
            if(root->left == NULL && root->right == NULL){
                return NULL;          
            }
            else if(root->left == NULL){
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == NULL){
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            }
            else{
                TreeNode* ptr = root->right;
                while(ptr != NULL && ptr->left != NULL){
                    ptr = ptr->left;
                }
                root->val = ptr->val;
                root->right = deleteNode(root->right, ptr->val);
            }
        }
        return root;
    }
};

// another solution
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root)
            if(key < root->val) root->left = deleteNode(root->left, key);     //We recursively call the function until we find the target node
            else if(key > root->val) root->right = deleteNode(root->right, key);
            else{
                if(!root->left && !root->right) return NULL;          //No child condition
                if (!root->left || !root->right)
                    return root->left ? root->left : root->right;    //One child condition -> replace the node with it's child
                //Two child condition
                TreeNode* temp = root->left;                        //(or) TreeNode *temp = root->right;
                while(temp->right != NULL) temp = temp->right;     //      while(temp->left != NULL) temp = temp->left;
                root->val = temp->val;                            //       root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);  //        root->right = deleteNode(root->right, temp);
            }
        return root;
    }
};