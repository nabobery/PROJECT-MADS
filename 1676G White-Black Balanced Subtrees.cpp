#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    vector<Node*> children;
    char ch;
    Node(int val, char c){
        data = val;
        ch = c;
    }
};

int dfs(Node* root, int &count){
    int currSum = root->ch == 'B' ? 1 : -1;
    for(auto node : root->children){
        currSum += dfs(node,count);
    }
    if(!currSum) count++;
    return currSum;
}

void solve(){
    int n;
    cin >> n;
    string s;
    int arr[n-1];
    for(int i = 0; i < n-1;i++) cin >> arr[i];
    cin >> s;
    Node *created[n];
    for (int i=0; i<n; i++) created[i] = NULL;
    Node* root = new Node(1,s[0]);
    created[0] = root;
    for(int i = 0; i < n-1;i++){
        Node* newNode = new Node(i+2,s[i+1]);
        created[i+1] = newNode;
        created[arr[i] - 1]->children.push_back(newNode);
    }
    int result = 0;
    dfs(root,result);
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}





