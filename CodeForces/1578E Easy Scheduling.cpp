#include <iostream>
#include <cmath>
using namespace  std;

void solve(){
    int h, p,i;
    cin >> h >> p;
    long long int base = 1,result;
    for(i = 0; i < h;i++){
        if(p <= base) break;
        base *= 2;
    }
    result = pow(2,h) - 1;
    result -= (base - 1);
    result = ceil((double)result/p);
    result += i;
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

