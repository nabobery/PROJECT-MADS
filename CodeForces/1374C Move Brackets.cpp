#include <iostream>
#include <stack>
using namespace  std;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    stack<char> stk;
    int result = 0;
    for(int i = 0; i < n;i++){
        if(s[i] == '(') stk.push('(');
        else{
            if(stk.empty()) result++;
            else stk.pop();
        }
    }
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
