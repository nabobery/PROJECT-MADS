#include <iostream>
using namespace std;

void solve(){
    string grid[9];
    for(int i = 0; i < 9;i++){
        cin >> grid[i];
    }
    int j = 0, k = 0;
    for(int i = 0; i < 3;i++){
        int temp = k, t = j+3;
        for(; j < t;j++){
            if(grid[j][temp] < '9'){
                grid[j][temp]++;
            }
            else grid[j][temp]--;
            temp += 3;
        }
        k++;
    }
    for(int i = 0; i < 9;i++){
        cout<<grid[i]<<"\n";
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


