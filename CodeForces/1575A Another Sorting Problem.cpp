#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace  std;

bool customCompare(pair<string,int>& a,pair<string,int>& b){
    string s1 = a.first;
    string s2 = b.first;
    for(int i = 0; i < s1.size();i++){
        if(s1[i] == s2[i]) continue;
        else{
            if(i % 2 == 0){
                return s1[i] < s2[i];
            }
            else{
                return s1[i] > s2[i];
            }
        }
    }
    return false;
}

void solve(){
    int n, m;
    string x;
    cin >> n >> m;
    vector<pair<string,int>> vec;
    for(int i = 0; i < n;i++){
        cin >> x;
        vec.push_back({x,i+1});
    }
    sort(vec.begin(),vec.end(), customCompare);
    for(auto itr : vec){
        cout<<itr.second<<" ";
    }
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
