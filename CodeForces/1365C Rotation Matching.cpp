#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast")

// aim to find maximum number of pairs after cyclic shifts. We can observe that n configurations are possible (for each permutation) using cyclic shifts and we need to get the maximum possible pairs possible using any configuration
void solve(){
    int n, x, result = 0;
    cin >> n;
    // for storing positions of 1 to n in arrays and counter of number of shifts required to make ai = bj where i = j
    int pos_a[n+1], pos_b[n+1], shifts[n];
    for(int i = 0; i < n;i++){
        cin >> x;
        pos_a[x] = i;
        shifts[i] = 0;
    }
    for(int i = 0; i < n;i++){
        cin >> x;
        pos_b[x] = i;
    }
    // get the number of shifts such that number i can be at the same position in a and b
    for(int i = 1; i <= n;i++){
        int temp = (pos_a[i] - pos_b[i] + n) % n;
        shifts[temp]++;
    }
    // get the maximum frequency of a shift so that we can get maximum number of pairs possible
    for(auto shift : shifts){
        if(shift > result) result = shift;
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

