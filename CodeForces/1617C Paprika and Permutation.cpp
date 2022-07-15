#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

void solve(){
    int n, result = 0;
    cin >> n;
    int arr[n];
    set <int> s;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        s.insert(i+1);
    }
    sort(arr, arr+n);
    for(int i = 0; i < n;i++){
        if(s.find(arr[i]) != s.end()) s.erase(arr[i]);
        else{
            auto it = s.begin();
            if(arr[i] - *it > *it){
                s.erase(it);
                result++;
            }
            else{
                result = -1;
                break;
            }
        }
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
