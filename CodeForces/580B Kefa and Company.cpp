#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n, d;
    cin >> n >> d;
    vector<pair<int,int>> vec(n);
    ll result = 0,temp = 0;
    for(int i = 0; i < n;i++){
        cin >> vec[i].first >> vec[i].second;
    }
    // sort based on money
    sort(vec.begin(),vec.end());
    // use 2 pointers to find segments such that m[r] - m[l] < d and get the maximum friendship of all such segments
    int l=0,r = 0;
    for(l = 0; l < n;l++){
        while(r < n && abs(vec[l].first - vec[r].first) < d){
            temp += vec[r].second;
            r++;
        }
        result = max(temp, result);
        temp -= vec[l].second;
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}





