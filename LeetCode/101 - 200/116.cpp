// 116. Populating Next Right Pointers in Each Node
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
// iterative solution similar to level order traversal using queue
class Solution {
public:
    Node* connect(Node* root) {
        queue <Node*> q;
        if(root)
            q.push(root);
        while(q.size()){
            int len = q.size();
            Node* curr;
            while(len--){
                curr = q.front();
                q.pop();
                curr->next = len ? q.front() : NULL;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return root;
    }
};

// iterative solution with O(n) time and O(1) memory without using queue
class Solution {
public:
    Node* connect(Node* root) {
        Node *prev = root, *curr;
        while (prev) {
            curr = prev;
            while (curr && curr->left) {
                curr->left->next = curr->right;
                if (curr->next) {
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }
            prev = prev->left;
        }
        return root;
    }
};

// recursive solution
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return NULL;
        }
        if (root -> left) {
            root -> left -> next = root -> right;
            if (root -> next) {
                root -> right -> next = root -> next -> left;
            }
            connect(root -> left);
            connect(root -> right);
        }
        return root;
    }
};


