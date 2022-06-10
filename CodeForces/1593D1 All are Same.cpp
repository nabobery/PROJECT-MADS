#include <iostream>
#include <vector>
using namespace  std;

int GCD(int a, int b){
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

void solve(){
    int n, min = 1e7;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        if(arr[i] < min) min = arr[i];
    }
    vector<int> gcd;
    for(int i = 0; i < n;i++){
        if(min == arr[i]) continue;
        else gcd.push_back(arr[i] - min);
    }
    if(gcd.empty()) cout<<"-1\n";
    else{
        if(gcd.size() == 1) cout<<gcd[0]<<"\n";
        else{
            int result = gcd[0];
            for(int i = 1; i < gcd.size(); i++){
                result = GCD(result,gcd[i]);
            }
            cout<<result<<"\n";
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

