#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    int arr[m];
    for(int i = 0; i < m;i++){
        cin >> arr[i];
    }
    int counter = 0,result = n;
    sort(arr, arr + m);
    int diff[m];
    for(int i = 1; i < m;i++){
        diff[i-1] = arr[i] - arr[i-1]-1;
    }
    diff[m-1] = n - arr[m-1] + arr[0] - 1;
    sort(diff, diff + m);
    for(int i = m-1; i > -1;i--){
        if(diff[i] - 2*counter <= 0) break;
        else{
            diff[i] -= 2*counter;
            if(diff[i] > 2){
                result -= (diff[i] - 1);
                counter += 2;
            }
            else{
                result--;
                counter++;
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
