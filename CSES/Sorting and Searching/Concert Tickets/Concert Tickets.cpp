#include <iostream>
#include <map>
using namespace  std;

void solve(){
    int n, m,h,t;
    cin >> n >> m;
    map<int,int> mp;
    for(int i = 0; i < n;i++){
        cin >> h;
        mp[h]++;
    }
    for(int i = 0; i < m;i++){
        cin >> t;
        auto it = mp.lower_bound(t);
        if(it->first == t){
            cout<< (it->first)<<"\n";
            it->second -= 1;
            if(it->second == 0) mp.erase(it->first);
        }
        else{
            if(it != mp.begin()){
                it--;
                if(it->first < t){
                    cout<< (it->first)<<"\n";
                    it->second -= 1;
                    if(it->second == 0) mp.erase(it->first);
                }
            }
            else cout<<"-1\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

