#include <iostream>
#include <cstring>
using namespace std;

int arr[7];

bool checkXOR(int x){
    for(int i = 0; i < 7;i++){
        int curr = arr[i] - (x&1);
        if(curr ^ (x&1)) return false;
        x >>= 1;
    }
    return true;
}

void solve(){
    int n,temp;
    cin >> n;
    memset(arr, 0, sizeof(arr));
    int a[n];
    for(int i = 0; i < n;i++){
        cin >> a[i];
        temp = a[i];
        int j = 0;
        while(temp){
            if(temp & 1) arr[j]++;
            temp >>= 1;
            j++;
        }
    }
    int result = a[0];
    for(int i = 0; i < n;i++){
        if(checkXOR(a[i])){
            result = a[i];
            break;
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


