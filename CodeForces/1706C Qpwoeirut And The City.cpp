#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int

// number of cool building is [n-1/2] (floor)

void solve(){
    int n;
    cin >> n;
    int arr[n+1];
    for(int i = 1; i <= n;i++) cin >> arr[i];
    ll result = 0;
    for(int i = 2; i < n;i += 2){
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) continue;
        else result += (max(arr[i+1],arr[i-1]) - arr[i] + 1);
    }
    // if it's odd there's only one way of being cool buildings
    // 1 [2] 1 [4] 3
    if(n %2) cout<<result<<"\n";
    // if it's even it can be complex so we calculate the odd way and then go backwards and see if choosing that building was better or
    // the building before that and get the minimum result
    else{
        ll temp = result;
        for(int i = n-1; i > 1; i -= 2){
            temp -= ((arr[i-1] > arr[i-2] && arr[i-1] > arr[i]) ? 0 : (max(arr[i],arr[i-2]) - arr[i-1] + 1));
            temp += ((arr[i] > arr[i-1] && arr[i] > arr[i+1]) ? 0 : (max(arr[i+1],arr[i-1]) - arr[i] + 1));
            result = min(result,temp);
        }
        cout<<result<<"\n";
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



