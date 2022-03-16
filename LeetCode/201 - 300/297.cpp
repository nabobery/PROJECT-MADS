// 297. Serialize and Deserialize Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // my naive solution by using level order
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            TreeNode* node = q.front();
            if(!node) result += ",null";
            else{
                if(flag){
                    result += ",";
                    result += to_string(node->val);
                }
                else{
                    result += to_string(node->val);
                    flag = true;
                }
            }
            q.pop();
            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        if(!data.size()) return root;
        queue<TreeNode*> q;
        stringstream x(data);
        string temp;
        getline(x,temp, ',');
        root = new TreeNode(stoi(temp));
        bool is_left = true;
        TreeNode *curr = NULL;
        q.push(root);
        while(getline(x,temp, ',')){
            TreeNode* node = NULL;
            if(temp != "null"){
                node = new TreeNode(stoi(temp));
                q.push(node);
            }
            if(is_left){
                curr = q.front();
                q.pop();
                curr->left = node;
                is_left = false;
            }
            else{
                curr->right = node;
                is_left = true;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

