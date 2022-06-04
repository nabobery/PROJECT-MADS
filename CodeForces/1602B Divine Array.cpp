#include <iostream>
#include <vector>
#include <map>
using namespace  std;

bool check(map<int,int>& mp){
    for(auto itr : mp){
        if(itr.first != itr.second) return true;
    }
    return false;
}

void solve(){
    int n, q,x,y;
    cin >> n;
    map<int,int> mp, tmp;
    vector<vector<int>> res;
    vector<int> temp;
    for(int i = 0; i < n;i++){
        cin >> x;
        temp.push_back(x);
        mp[x]++;
    }
    res.push_back(temp);
    while(check(mp)){
        for(int i = 0; i < n;i++){
            temp[i] = mp[res.back()[i]];
            tmp[temp[i]]++;
        }
        mp = tmp;
        tmp.clear();
        res.push_back(temp);
    }
    cin >> q;
    for(int i = 0; i < q;i++){
        cin >> x >> y;
        if(y > (res.size() - 1)){
            cout<<res.back()[x-1]<<"\n";
        }
        else{
            cout<<res[y][x-1]<<"\n";
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

