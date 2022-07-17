#include <iostream>
#include <map>
using namespace std;

void solve(){
    int n,x;
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n;i++){
        cin >> x;
        mp[x] = i;
    }
    int rounds = 1, index = mp[1];
    for(int i = 2;i <= n; i++){
        if(mp[i] < index){
            rounds++;
        }
        index = mp[i];
    }
    cout<<rounds<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}





