#include <iostream>
#include <stack>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n];
    stack<int> stk;
    for(int i = 0; i < n;i++) cin >> arr[i];
    for(int i = 0; i < n;i++){
        while(!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop();
        if(stk.empty()) cout<<"0 ";
        else cout<<stk.top()+1<<" ";
        stk.push(i);
    }
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
