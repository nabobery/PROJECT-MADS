#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    if(n % 2) cout<<"-1\n";
    else{
        vector<pair<int,int>> result;
        for(int i = 0; i < n;i+=2){
            if(arr[i] == arr[i+1]){
                result.push_back({i+1,i+2});
            }
            else{
                result.push_back({i+1,i+1});
                result.push_back({i+2,i+2});
            }
        }
        cout<<result.size()<<"\n";
        for(auto itr : result) cout<<itr.first<<" "<<itr.second<<"\n";
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





