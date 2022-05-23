#include <iostream>
using namespace  std;

void solve(){
    string n;
    cin >> n;
    int temp = 9;
    if(n.size() == 2){
        cout<<n[1]<<"\n";
    }
    else{
        for(char ch: n){
            if(temp > ch - '0')
                temp = ch - '0';
        }
        cout<<temp<<"\n";
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




