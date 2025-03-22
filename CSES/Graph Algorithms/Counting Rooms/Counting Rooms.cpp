#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

int mod = 1e9 + 7;


// basic bfs to traverse all the cells connected to the current cell
void helper(pair<int,int> p, vector<vector<char>>& grid){
    int n = grid.size(), m = grid[0].size();
    queue<pair<int,int>> q;
    grid[p.first][p.second] = '#';
    q.push(p);
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        if(curr.first+1 < n && grid[curr.first+1][curr.second] == '.'){
            q.push({curr.first+1, curr.second});
            grid[curr.first+1][curr.second] = '#';
        }
        if(curr.first-1 >= 0 && grid[curr.first-1][curr.second] == '.'){
            q.push({curr.first-1, curr.second});
            grid[curr.first-1][curr.second] = '#';
        }
        if(curr.second+1 < m && grid[curr.first][curr.second+1] == '.') {
            q.push({curr.first, curr.second+1});
            grid[curr.first][curr.second+1] = '#';
        }
        if(curr.second-1 >= 0 && grid[curr.first][curr.second-1] == '.') {
            q.push({curr.first, curr.second-1});
            grid[curr.first][curr.second-1] = '#';
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n;i++)
        for(int j = 0; j < m;j++)
            cin >> grid[i][j];
    int result = 0;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            if(grid[i][j] == '.'){
                helper({i,j}, grid);
                result++;
            }
        }
    }
    cout<<result<<"\n";
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
