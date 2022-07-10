#include <iostream>
using namespace std;

/*For every i that a1,a2,...,ai is a permutation of 1,2,...,i we have a new connected component.
Therefore if we encounter a element which completed its permutation(max == number of elements) it implies that there was a
connected component(sub array is the connected component)*/

void solve(){
    int n,x,max = 0,result = 0;
    cin >> n;
    for(int i = 1; i <= n;i++){
        cin >> x;
        if(x > max) max = x;
        if(max == i) result++;
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

