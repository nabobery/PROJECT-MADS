#include <iostream>
#include <algorithm>
#include <vector>
using namespace  std;

void solve(){
    int n,x;
    cin >> n >> x;
    vector<int> vec(n);
    for(int i = 0; i < n;i++){
        cin >> vec[i];
    }
    vector<int> temp = vec;
    vector<int> indices;
    sort(vec.begin(),vec.end());
    for(int i = 0; i < n;i++){
        int t1 = i - x;
        int t2 = i + x;
        if((t1 >= 0 && t1 < n) || ((t2 >= 0 && t2 < n))) continue;
        else indices.push_back(i);
    }
    bool flag = false;
    for(auto itr : indices){
        if(vec[itr] ==  temp[itr]) continue;
        else{
            flag = true;
            break;
        }
    }
    if(!flag) cout<<"YES\n";
    else cout<<"NO\n";
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
