#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

int result = 0,n,m;

vector<bool> visited, a;

void dfs(int v,int count, vector<int> list[]){
    visited[v] = true;
    if(a[v]) count += a[v];
    else count = 0;
    if(count > m) return;
    bool flag = false;
    for(auto it : list[v]){
        if(!visited[it]){
            flag = true;
            break;
        }
    }
    if(!flag){
        result++;
        return;
    }
    for(auto it : list[v]){
        if(!visited[it])
            dfs(it,count,list);
    }
}

void solve(){
    int x,y;
    cin >> n >> m;
    vector<int> adjlist[n];
    for(int i = 0; i < n;i++){
        cin >> x;
        a.push_back(x);
        visited.push_back(false);
    }
    for(int i = 1; i < n;i++){
        cin >> x >> y;
        adjlist[x-1].push_back(y-1);
        adjlist[y-1].push_back(x-1);
    }
    dfs(0,0, adjlist);
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}






