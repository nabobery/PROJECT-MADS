#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast")

// greedy solution
void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    if(n == 1) cout<<"0\n";
    else{
        // all elements equal in an array is a non-decreasing array
        cout<<n-1<<"\n";
        // make a1 = an
        cout<<"1 "<<n<<"\n";
        // then just make all elements equal
        for(int i = 1; i < n-1;i++){
            // make ai = a1 as ar = al
            if((arr[i] + arr[0]) % 2) cout<<"1 "<<i+1<<"\n";
            // make ai = an as al = ar
            else cout<<i+1<<" "<<n<<"\n";
        }
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


