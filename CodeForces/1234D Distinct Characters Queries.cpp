#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
 
#pragma GCC optimize("Ofast")
 
#define ll long long int
 
void solve(){
    string s;
    cin >> s;
    int q, op;
    cin >> q;
    vector<set<int>> vec(26, set<int>());
    // maintain an array of set with indices of each character
    for(int i = 0; i < s.size();i++) vec[s[i] - 'a'].insert(i+1);
    for(int i = 0; i < q;i++){
        cin >> op;
        // if operation 1 remove the index for the prev character and add the index for the new character
        if(op == 1){
            int pos;
            char c;
            cin >> pos >> c;
            vec[s[pos-1] - 'a'].erase(pos);
            vec[c - 'a'].insert(pos);
            s[pos-1] = c;
        }
        else{
            int l,r;
            cin >> l >> r;
            int result = 0;
            for(int i = 0; i < 26;i++){
                // if there is any index between [l,r] in the character set then increment result
                if(vec[i].lower_bound(l) != vec[i].upper_bound(r)) result++;
            }
            cout<<result<<"\n";
        }
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}