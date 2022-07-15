#include <iostream>
#include <cmath>
using namespace std;

long long int count(int x){
    return 1ll*x*(x+1)/2;
}

void solve(){
    int k;
    long long int x;
    cin >> k >> x;
    bool flag = false;
    int result = 2*k - 1;
    long long int l = 1, r = result,mid;
    while(l <= r){
        mid = (l+r)/2;
        // 1st case when we can post more than or equal to k messages
        if(mid >= k){
            flag = (count(k) + count(k-1) - count(2*k - 1 -mid) >= x);
        }
        // 2nd case where we can post less than k messages
        else{
            flag = (count(mid) >= x);
        }
        if(flag){
            result = mid;
            r = mid -1;
        }
        else l = mid+1;
    }
    cout<<result<<"\n";
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



