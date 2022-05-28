#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;

int arr[100000];

bool check(int n){
    vector<int> temp;
    for(int i = 0; i < n/2;i++){
        temp.push_back(arr[i]);
        temp.push_back(arr[n/2 + i]);
    }
    for(int i = 0; i < n;i++){
        if(i == 0){
            if((temp[i] > temp[n-1] && temp[i] > temp[i+1]) || (temp[i] < temp[n-1] && temp[i] < temp[i+1])) continue;
            else return false;
        }
        else if(i == n -1){
            if((temp[i] > temp[0] && temp[i] > temp[i-1]) || (temp[i] < temp[0] && temp[i] < temp[i-1])) continue;
            else return false;
        }
        else{
            if((temp[i] > temp[i+1] && temp[i] > temp[i-1]) || (temp[i] < temp[i+1] && temp[i] < temp[i-1])) continue;
            else return false;
        }
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++) cin >> arr[i];
    sort(arr, arr + n);
    if(n % 2 == 1) cout<<"NO\n";
    else{
        if(check(n)){
            cout<<"YES\n";
            for(int i = 0; i < n/2;i++){
                cout<<arr[i]<< " "<< arr[n/2 + i]<<" ";
            }
            cout<<"\n";
        }
        else{
            cout<<"NO\n";
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


