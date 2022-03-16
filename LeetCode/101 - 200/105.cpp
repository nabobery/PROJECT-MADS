// 105. Construct Binary Tree from Preorder and Inorder Traversal
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
 // inspiration from 106 solution (iterative and using space)
 // O(n) time and O(N) space solution
 // Inorder (Left, Root, Right) and Preorder (Root, Left, Right)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        stack<TreeNode*> stk;
        set<TreeNode*> s;
        TreeNode* root = NULL;
        for(int p = 0, i = 0; p < n;){
            TreeNode* node = NULL;
            do{
                node = new TreeNode(preorder[p]);
                if(root == NULL){
                    root = node;
                }
                if(stk.size() > 0){
                    if(s.find(stk.top()) != s.end()){
                        s.erase(stk.top());
                        stk.top()->right = node;
                        stk.pop();
                    }
                    else{
                        stk.top()->left = node;
                    }
                }
                stk.push(node);
            } while(preorder[p++] != inorder[i] && p < n);
            node = NULL;
            while(stk.size() > 0 && i < n && stk.top()->val == inorder[i]){
                node = stk.top();
                stk.pop();
                i++;
            }
            if(node != NULL){
                s.insert(node);
                stk.push(node);
            }

        }
        return root;
    }
};

// recursive O(n) Time and O(n) space solution
// Idea : Think of a tree of trees as subtrees are also trees
class Solution {
public:
    int preorderIndex;
    // a hashmap to store inorder index value
    unordered_map <int,int> inorderIndexMap;
    TreeNode* helper(vector<int>& preorder, int left, int right){
        // if there are no elements to build the tree
        if(left > right) return NULL;
        // get the root of the given tree and increment it to the get the next one
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        // build the left subtree
        root->left = helper(preorder,left, inorderIndexMap[rootVal] - 1);
        // build the right subtree
        root->right = helper(preorder,inorderIndexMap[rootVal] + 1, right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i < n;i++){
            inorderIndexMap[inorder[i]] = i;
        }
        return helper(preorder,0, n-1);

    }
};

