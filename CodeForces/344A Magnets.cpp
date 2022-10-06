#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int n;
    cin >> n;
    string magnet;
    char end;
    int result = 1;
    cin >> magnet;
    end = magnet[1];
    for(int i = 1; i < n;i++){
        cin >> magnet;
        if(end == magnet[0]){
            result++;
        }
        end = magnet[1];
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}



