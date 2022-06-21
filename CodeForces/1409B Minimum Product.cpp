#include <iostream>
#include <algorithm>
using namespace  std;

void solve(){
    int n,a,b,x,y;
    cin >> a >> b >> x >> y >> n;
    long long int result = 1e18;
    int diff1 = a-x, diff2 = b-y;
    if(diff1 >= n){
        long long int t = a-n;
        t *= b;
        result = min(t,result);
    }
    else if(diff1 < n){
        int temp = n - diff1;
        if(diff2 >= temp){
            long long int t = (b - temp);
            t *= x;
            result = min(t,result);
        }
        else{
            long long int t = x;
            t *= y;
            result = min(t,result);
        }
    }
    if(diff2 >= n){
        long long int t = b-n;
        t *= a;
        result = min(t,result);
    }
    else if(diff2 < n){
        int temp = n - diff2;
        if(diff1 >= temp){
            long long int t = (a - temp);
            t *= y;
            result = min(t,result);
        }
        else{
            long long int t = x;
            t *= y;
            result = min(t,result);
        }
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
