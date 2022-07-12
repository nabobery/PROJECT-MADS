#include <iostream>
using namespace std;

void solve(){
    string board[8];
    for(int i = 0; i < 8;i++){
        cin >> board[i];
    }
    bool flag = false;
    for(int i = 1; i < 7;i++){
        for(int j = 1; j < 7;j++){
            if(board[i-1][j-1] == '#' && board[i+1][j+1] == '#' && board[i-1][j+1] == '#' && board[i+1][j-1] == '#'){
                cout<<i+1<<" "<<j+1<<"\n";
                flag = true;
                break;
            }
        }
        if(flag) break;
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
