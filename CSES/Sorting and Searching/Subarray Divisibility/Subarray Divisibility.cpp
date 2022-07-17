#include <iostream>
#include <map>
using namespace std;

void solve(){
    int n,ai;
    long long int sum = 0, result = 0;
    cin >> n;
    map<int,int> mp;
    for(int i = 0; i < n;i++){
        cin >> ai;
        sum += ai;
        mp[((sum%n)+n)%n]++;
    }
    for(auto itr : mp){
        // sub arrays such that their difference is sum mod n == 0
        result += ((long long int)(itr.second)*(itr.second - 1))/2;
    }
    // subarrays whose sum mod n is equal to 0
    result += mp[0];
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
