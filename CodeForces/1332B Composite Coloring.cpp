#include <iostream>
#include <vector>
using namespace std;

#pragma GCC optimize("Ofast")

int primes[11] = {2,3,5,7,11,13,17,19,23,29,31};

void solve(){
    int n,counter = 0;
    cin >> n;
    int arr[n];
    vector<vector<int>> vec(11);
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        for(int j = 0; j < 11;j++){
            if(arr[i] % primes[j] == 0){
                vec[j].push_back(i);
                break;
            }
        }
    }
    for(int i = 0; i < 11;i++){
        if(!vec[i].empty()){
            ++counter;
            for(auto it : vec[i]){
                arr[it] = counter;
            }
        }
    }
    cout<<counter<<"\n";
    for(auto a : arr) cout<<a<<" ";
    cout<<"\n";
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

