#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;

bool check(vector<vector<int>> grid, vector<vector<int>> old){
    for(int i = 0; i < grid.size();i++){
        for(int j = 0; j < grid[i].size();j++){
            if(grid[i][j] != old[i][j]) return false;
        }
    }
    return true;
}

void solve(){
    vector<vector<int>> grid, old;
    int n, m,x,ind = -1;
    cin >> n >> m;
    for(int i = 0; i < n;i++){
        vector<int> temp;
        for(int j = 0; j < m;j++){
            cin >> x;
            temp.push_back(x);
        }
        old.push_back(temp);
        sort(temp.begin(),temp.end());
        grid.push_back(temp);
        if(temp != old[i]){
            ind = i;
        }
    }
    if(ind  == -1) cout<<"1 1 \n";
    else{
        vector<int> indices;
        bool flag = false;
        for(int j = 0; j < grid[ind].size();j++){
            if(old[ind][j] != grid[ind][j]){
                indices.push_back(j+1);
            }
            if(indices.size() > 2){
                flag = true;
                break;
            }
        }
        if(flag) cout<< -1 <<"\n";
        else if(indices.size() == 2){
            bool b = false;
            int index1 = indices[0] - 1, index2 = indices[1] - 1;
            for(int i = 0; i < grid.size();i++){
                if(grid[i][index1] == old[i][index2] && grid[i][index2] == old[i][index1]){
                    old[i][index1] = grid[i][index1];
                    old[i][index2] = grid[i][index2];
                }
                else{
                    b = true;
                    break;
                }
            }
            if(b) cout<< -1<<"\n";
            else{
                if(check(grid,old)) cout<<indices[0]<<" "<<indices[1]<<"\n";
                else cout<< -1<<"\n";
            }
        }
    }

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




