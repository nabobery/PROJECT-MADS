#include <iostream>
using namespace std;

// number of times ball is passed is sum(a). if 2*max(a) <= sum(a) then it can be done using only 1 ball else 2*max(a) - sum(a)
// max -> __ max -> __ ... (if max(a) <= sum(a) - max(a)[number of blanks] means we can fill the blanks and end it with one ball else we need to end the path and start another)

void solve(){
    int n,x, max = 0;
    cin >> n;
    long long int sum = 0;
    for(int i = 0; i < n;i++){
        cin >> x;
        if(x > max) max = x;
        sum += x;
    }
    if(max == 0) cout<<"0\n";
    else{
        if(2*max <= sum) cout<<"1\n";
        else cout<<2*max - sum<<"\n";
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








