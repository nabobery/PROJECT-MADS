#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n;
    string s;
    cin >> n >> s;
    stack <char> stk;
    for(auto ch : s){
        if(ch == 'Q') stk.push(ch);
        else{
            if(!stk.empty()) stk.pop();
        }
    }
    cout<<(stk.empty() ? "Yes\n" : "No\n");
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
