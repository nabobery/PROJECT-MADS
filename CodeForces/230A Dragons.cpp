#include<bits/stdc++.h>
using namespace  std;

void solve(){
    int s, n, x, y;
    cin >> s >> n;
    vector<pair<int,int>> vec;
    for(int i = 0; i < n;i++){
        cin >> x >> y;
        vec.push_back(make_pair(x,y));
    }
    sort(vec.begin(), vec.end());
    bool flag = false;
    for(int i = 0; i < n;i++) {
        if (s > vec[i].first) s += vec[i].second;
        else{
            flag = true;
            break;
        }
    }
    if(!flag) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    solve();
    return 0;
}

