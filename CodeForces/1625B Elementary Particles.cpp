#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace  std;

void solve(){
    int n,x;
    cin >> n;
    int result = -1;
    unordered_map<int, vector<int>> mp;
    for(int i = 0; i < n;i++){
        cin >> x;
        mp[x].push_back(i);
    }
    if(mp.size() == n) cout<<result<<"\n";
    else if(mp.size() == 1) cout<< n-1<<"\n";
    else{
        for(auto itr : mp){
            for(int i = 0; i < itr.second.size() -1;i++){
                int size = n + itr.second[i] - itr.second[i+1];
                result = max(result,size);
            }
        }
        cout<<result<<"\n";
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


