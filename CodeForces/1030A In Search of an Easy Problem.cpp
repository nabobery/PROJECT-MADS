#include <iostream>
using namespace  std;

void solve(){
    int n, x;
    cin >> n;
    bool flag = false;
    for(int i = 0; i < n;i++){
        cin >> x;
        if(x == 1){
            flag = true;
            break;
        }
    }
    if(flag) cout<<"HARD\n";
    else cout<<"EASY\n";
}

int main() {
    solve();
    return 0;
}


