#include <iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n];
    int min = 1e6 + 1;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        if(min > arr[i]) min = arr[i];
    }
    int counter = 0;
    for(int i = 0; i < n && counter < n/2;i++){
        if(arr[i] != min){
            cout<<arr[i]<<" "<<min<<"\n";
            counter++;
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


