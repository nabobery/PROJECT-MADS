#include <iostream>
#include <climits>
using namespace  std;

// Kadane's Algorithm
void solve(){
    int n,x;
    long long int curr_max = 0, result = INT_MIN;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> x;
        curr_max += x;
        if(result < curr_max) result = curr_max;
        if(curr_max < 0) curr_max = 0;
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

