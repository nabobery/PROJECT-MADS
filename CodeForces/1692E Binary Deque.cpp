#include <iostream>
#include <map>
using namespace std;

// we find out the maximum sub array length such that sum is s
// and then get the number of operations as n - sum
void solve(){
    int n,sum = 0,s,x, result = 0;
    cin >> n >> s;
    map<int,int> mp;
    // base case as sum is 0 from the start
    mp[0] = -1;
    for(int i = 0; i < n;i++){
        cin >> x;
        sum += x;
        // set the first index for the given sum
        if(x == 1) mp[sum] = i;
        if(sum >= s){
            int temp = sum - s;
            // check for left end of array after which the array starts
            auto it = mp.lower_bound(temp);
            // get length
            temp = (i - it->second);
            // get max
            result = max(temp,result);
        }
    }
    if(result == 0) cout<< -1<<"\n";
    else cout<<n-result<<"\n";
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



