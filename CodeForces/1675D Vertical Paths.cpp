#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
    int data;
    vector<Node*> children;
    Node(int val){
        data = val;
    }
};

void numberofPaths(Node* root, int &count){
    if(!root) return;
    if(root->children.empty()){
        count++;
        return;
    }
    for(auto node : root->children){
        numberofPaths(node,count);
    }
}

void getAllPaths(Node* root, string &path, int &counter){
    if(!root) return;
    counter++;
    path += (to_string(root->data) + " ");
    if(root->children.empty()){
        cout<<counter<<"\n";
        cout<<path<<"\n";
        path = "";
        counter = 0;
        return;
    }
    for(auto node : root->children){
        getAllPaths(node,path,counter);
    }
}

void solve(){
    int n, p;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        if(arr[i] == i+1) p = arr[i];
    }
    Node *root = new Node(p);
    Node *created[n+1];
    for (int i=0; i<=n; i++) created[i] = NULL;
    created[p] = root;
    for(int i = 1; i <= n;i++){
        if(p != i){
            Node* newNode = new Node(i);
            created[i] = newNode;
        }
        else continue;
    }
    for(int i = 0; i < n;i++){
        if(p != i+1){
            created[arr[i]]->children.push_back(created[i+1]);
        }
        else continue;
    }
    int paths = 0,counter = 0;
    numberofPaths(root,paths);
    cout<<paths<<"\n";
    string temp = "";
    getAllPaths(root,temp,counter);
    cout<<"\n";
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





