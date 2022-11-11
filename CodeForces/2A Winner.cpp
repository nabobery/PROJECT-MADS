#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n,m = -1001;
    cin >> n;
    map<string,int> mp;
    vector<string> name(n);
    vector<int> score(n);
    set<string> temp;
    for(int i = 0; i < n;i++){
        cin >> name[i] >> score[i];
        mp[name[i]] += score[i];
    }
    for(auto itr : mp){
        if(itr.second > m) m = itr.second;
    }
    for(auto itr : mp){
        if(itr.second == m) temp.insert(itr.first);
    }
    mp.clear();
    for(int i = 0; i < n;i++){
        mp[name[i]] += score[i];
        if(mp[name[i]] >= m && temp.count(name[i])){
            cout<<name[i]<<"\n";
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}






