#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <algorithm>
//#include <cstring>
#include <stack>
using namespace std;
 
#pragma GCC optimize("Ofast")
 
#define ll long long int
 
vector<vector<char>> adj(26, vector<char>());
 
string result;
 
bool dfs(vector<bool>& visited,vector<bool>& currpath, char v){
    // if current path(component) is leading to a cycle
    if(currpath[v]) return false;
    // if already visited means there's a topological sorting
    if(visited[v]) return true;
    currpath[v] = true;
    for(auto u : adj[v]){
        if(!dfs(visited, currpath, u)) return false;
    }
    // as the path is already traversed
    currpath[v] = false;
    if(!visited[v]) result += (v + 'a');
    visited[v] = true;
    return true;
}
 
void solve(){
    int n;
    cin >> n;
    string p, s; cin >> p;
    n--;
    while(n--){
        cin >> s;
        bool flag = false;
        for(int j = 0; j < min(p.size(), s.size());j++){
            if(p[j] != s[j]){
                flag = true;
                adj[p[j] - 'a'].push_back(s[j] - 'a');
                break;
            }
        }
        if(!flag && p.size() > s.size()) adj[0].push_back(0);
        p = s;
    }
    vector<bool> visited(26,false), currpath(26, false);
    for (int i = 0; i < 26; ++i) {
        if (!dfs(visited, currpath,i)) {
            cout<<"Impossible\n";
            return;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (!visited[i]) result += i + 'a';
    }
    for(int i = 25; i >= 0;i--) cout<<result[i];
    cout<<"\n";
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