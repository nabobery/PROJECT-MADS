#include <iostream>
#include <map>
#include <vector>
using namespace std;

void solve(){
    int n,k,x;
    cin >> n >> k;
    map<int,int> mp;
    for(int i = 0; i < n;i++){
        cin >> x;
        mp[x]++;
    }
    vector<int> result;
    for(auto itr : mp){
        if(itr.second >= k) result.push_back(itr.first);
    }
    int m = result.size();
    if(!m) cout<<"-1\n";
    else{
        int l = result[0], r = result[0], max = 0, curr = 1;
        for(int i = 1; i < m;i++){
            if(result[i-1]+1 == result[i]){
                curr++;
            }
            else{
                if(curr > max) max = curr;
                curr = 1;
            }
        }
        if(curr > max) max = curr;
        curr = 0;
        for(int i = 0; i < m;i++){
            l = result[i];
            while(i < m-1 && result[i]+1 == result[i+1]){
                curr++;
                i++;
            }
            if(curr+1 == max){
                r = result[i];
                break;
            }
            curr = 0;
        }
        cout<<l<<" "<<r<<"\n";
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



