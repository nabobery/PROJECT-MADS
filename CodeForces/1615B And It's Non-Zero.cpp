#include <iostream>
#include <cmath>
using namespace std;

int getNumberOfBitsSet(int n, int i){
    // Gives the count of numbers having ith bit set till the nearest power of 2 less than n.
    int result = (n >> (i + 1)) << i;
    // if ith bit is set in n, then add nearest power of 2 less than n to result
    if((n >> i) & 1) result += n & ((1 << i) - 1);
    return result;
}

void solve(){
    int l, r,max = 0;
    cin >> l >> r;
    for(int i = 0; i < (int)log2(r) + 1;i++){
        int temp = getNumberOfBitsSet(r+1,i) - getNumberOfBitsSet(l,i);
        if(temp > max) max = temp;
    }
    cout<<(r-l+1)-max<<"\n";
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

