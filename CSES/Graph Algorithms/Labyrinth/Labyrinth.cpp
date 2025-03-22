#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

#pragma GCC optimize("Ofast")

const int dx[] = {0, -1, 0, 1};  // Row movement
const int dy[] = {-1, 0, 1, 0};  // Column movement
const char dir[] = {'L', 'U', 'R', 'D'};

bool isInsideGrid(int nx, int ny, int n, int m) {
    return (nx >= 0 && nx < n && ny >= 0 && ny < m);
}


// check if there is a path from A to B in a grid
void solve() {
    int n, m;
    cin >> n >> m;
    char grid[n][m];
    int start, end;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'A') start = i*m + j;
            else if (grid[i][j] == 'B') end = i*m + j;
        }
    }
    queue<int> q;
    unordered_map<int,int> prev;
    string result;
    vector<bool> visited(n*m, false);
    q.push(start);
    visited[start] = true;
    prev[start] = -1;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        if(curr == end)
            break;
        int x = curr/m, y = curr%m;
        for(int i = 0; i < 4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            int next = nx*m + ny;
            if(isInsideGrid(nx, ny, n, m) && !visited[next] && grid[nx][ny] != '#'){
                visited[next] = true;
                prev[next] = curr;
                q.push(next);
            }
        }
    }
    if(prev.count(end)){
        cout<<"YES\n";
        int curr = end;
        while(prev[curr] != -1){
            int dirx = (curr - prev[curr])/m, diry = (curr - prev[curr]) % m ;
            for(int d = 0; d < 4;d++){
                if(dx[d] == dirx && dy[d] == diry){
                    result += dir[d];
                    break;
                }
            }
            curr = prev[curr];
        }
        reverse(result.begin(), result.end());
        cout<<result.size()<<"\n";
        cout<<result<<"\n";
    }
    else cout<<"NO\n";
}



int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}




