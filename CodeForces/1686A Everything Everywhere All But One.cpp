#include <iostream>
#include <set>
using namespace std;

// if mean of n-1 elements is equal to some a[j]
// which means sum except a[j] = a[j].(n-1)
// which means sum/n = a[j] (by adding a[j] in both sides)
// therefore we can equate all elements with equal to mean if we have mean in the array

void solve(){
    int n,x;
    cin >> n;
    set<int> s;
    int sum = 0;
    for(int i = 0; i < n;i++){
        cin >> x;
        sum += x;
        s.insert(x);
    }
    int mean = sum/n;
    if(sum % n == 0) cout<< (s.count(mean) ? "YES\n" : "NO\n");
    else cout<<"NO\n";
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



