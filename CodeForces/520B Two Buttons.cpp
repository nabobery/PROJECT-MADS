#include <iostream>
using namespace std;

void solve(){
    int n,m, result = 0;
    cin >> n >> m;
    // we reverse engineer the operations and go from m to n
    while(n < m){
        // if m is odd, make it even and then divide it by 2
        if(m%2){
            result++;
            m++;
        }
        m /= 2;
        result++;
    }
    result += (n-m);
    cout<< result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}



