#include <iostream>
#include <map>
using namespace std;

void solve(){
    int n,x;
    cin >> n;
    map<int,int> mp;
    for(int i = 0; i < n;i++){
        cin >> x;
        mp[x]++;
    }
    int temp = 0;
    for(auto itr : mp){
        temp += (itr.second - 1);
    }
    if(temp % 2) cout<<mp.size()-1<<"\n";
    else cout<<mp.size()<<"\n";


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